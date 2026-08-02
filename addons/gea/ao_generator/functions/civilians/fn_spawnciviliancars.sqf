// =====================================================================
// GEA_fnc_spawnCivilianCars
//   Scatters EMPTY parked civilian cars on roads inside the AO - no
//   driver, just ambient set-dressing. Cars are offset onto a lane
//   (perpendicular to the road heading) and aligned to the road. The
//   offset is scaled to the road's REAL width via getRoadInfo, so cars
//   on narrow city streets stay near the centerline instead of clipping
//   into buildings; we try the chosen lane, then the opposite lane, then
//   the centerline before giving up.
//
//   Overlap-safe: every car checks the AO's shared "obstacles" registry
//   (which static turrets, vehicle patrols and roadblocks also populate)
//   so a car can never spawn on top of a roadblock or another placed
//   object - that used to make the car explode on spawn. Each car also
//   registers its own footprint so later placements avoid it.
//
//   Junction-safe: intersections/crossroads are detected up front
//   (a road segment that connects to more than 2 neighbours) and any
//   spawn point within civCarJunctionClearance metres of one is rejected,
//   so cars never end up parked half-way across a crossroad.
//
//   Pool source - two tier (faction, then civilian-side). Karts excluded.
//
//   Inputs:
//     _aoConfig : HashMap - reads center, radius, id, civFaction, civCars,
//                 civCarJunctionClearance (optional, default 15m).
//
//   Returns: array of created vehicle objects (for cleanup).
// =====================================================================
#include "..\..\script_component.hpp"
if (!isServer) exitWith { [] };
params [["_aoConfig", createHashMap, [createHashMap]]];
private _center     = _aoConfig get "center";
private _radius     = _aoConfig get "radius";
private _aoId       = _aoConfig get "id";
private _civFaction = _aoConfig getOrDefault ["civFaction", ""];
private _count      = _aoConfig getOrDefault ["civCars", 0];
private _say = {
    params ["_msg"];
    diag_log text format ["[GEA] civcar: %1", _msg];
};
if (_count <= 0) exitWith { [] };
// --- Build the civilian car pool ------------------------------------
private _factionCars = [];
private _sideCars    = [];
{
    private _cfg   = _x;
    private _class = configName _cfg;
    if (getNumber (_cfg >> "scope") >= 2
        && { _class isKindOf "Car" }
        && { !(_class isKindOf "StaticWeapon") }
        && { !(_class isKindOf "ParachuteBase") }
        && { !(_class isKindOf "Kart_01_base_F") }   // exclude go-karts
    ) then {
        if ((getText (_cfg >> "faction")) == _civFaction && _civFaction != "") then {
            _factionCars pushBack _class;
        };
        if ((getNumber (_cfg >> "side")) == 3) then {   // 3 = civilian
            _sideCars pushBack _class;
        };
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));
private _pool = if (count _factionCars > 0) then { _factionCars } else { _sideCars };
[format ["pool faction=%1 side=%2 -> using %3 classes", count _factionCars, count _sideCars, count _pool]] call _say;
if (_pool isEqualTo []) exitWith {
    ["NO civilian car classes found for faction OR civilian side - skipping."] call _say;
    []
};
// Cars only ever spawn on a road inside the AO radius.
private _roads = (_center nearRoads _radius) call BIS_fnc_arrayShuffle;
[format ["roads found in AO: %1 (radius %2m)", count _roads, _radius]] call _say;
if (_roads isEqualTo []) exitWith {
    ["no roads in the AO - skipping civilian cars."] call _say;
    []
};
// --- Intersection detection -----------------------------------------
// How far from any intersection a car must stay (metres).
private _junctionClearance = _aoConfig getOrDefault ["civCarJunctionClearance", 15];
// Roads in A3 are chains of segment objects (like spline pieces).
// roadsConnectedTo returns a segment's neighbours:
//   1 = dead-end, 2 = straight mid-road, 3+ = junction/crossroad.
// So any segment with more than 2 connections is an intersection node.
private _junctions = _roads select { count (roadsConnectedTo _x) > 2 };
[format ["intersections in AO: %1 (clearance %2m)", count _junctions, _junctionClearance]] call _say;
// True if a position is within clearance of any intersection node.
private _fnc_nearJunction = {
    params ["_pos", "_clear"];
    _junctions findIf { (_pos distance2D (getPosATL _x)) < _clear } >= 0
};
// Pre-filter the road list ONCE (cheaper than re-checking every car), and log
// how many segments survive. In a dense city grid this number can collapse to
// near zero because big roads are peppered with junctions - if so, that's why
// the wide central roads stay empty, and civCarJunctionClearance is too high.
private _spawnRoads = _roads select { !([getPosATL _x, _junctionClearance] call _fnc_nearJunction) };
[format ["usable segments after junction filter: %1 / %2", count _spawnRoads, count _roads]] call _say;
if (_spawnRoads isEqualTo []) exitWith {
    ["ALL road segments are within junction clearance - lower civCarJunctionClearance for this AO. Skipping."] call _say;
    []
};
private _created = [];
// Shared obstacle registry (also used by statics/vehicles/roadblocks).
private _obstacles = _aoConfig getOrDefault ["obstacles", []];
// Road heading from a connected neighbour.
private _fnc_roadDir = {
    params ["_road"];
    private _conn = roadsConnectedTo _road;
    if (count _conn > 0) then {
        (getPosATL _road) getDir (getPosATL (_conn select 0))
    } else {
        direction _road
    };
};
// Clear test: not water, not sitting ON a building/house, and not inside
// any registered obstacle footprint (roadblock, static, vehicle, car).
private _fnc_isClear = {
    params ["_p", "_r"];
    if (surfaceIsWater _p) exitWith { false };
    // On or right next to a building/house?
    if (!((nearestObjects [_p, ["Building","House"], 4]) isEqualTo [])) exitWith { false };
    // Any vehicle ALREADY physically in the world here? This is what catches
    // cars from a PREVIOUS AO spawn: each AO carries its own obstacle registry,
    // so cross-AO overlaps are invisible to the registry below. Scanning the
    // world also catches patrol vehicles, roadblock vehicles, wrecks, etc.
    if (!((nearestObjects [_p, ["LandVehicle","Ship","Air"], _r + 2]) isEqualTo [])) exitWith { false };
    // Any obstacle footprint registered during THIS AO run.
    (_obstacles findIf { (_p distance2D (_x select 0)) < ((_x select 1) + _r) }) < 0
};
private _carFootprint  = 4;
private _carHalfWidth  = 1.2;   // ~half a car's width, used for the lateral offset
private _safetyMargin  = 0.6;   // extra buffer to keep clear of the kerb / road edge
private _maxLaneOffset = 3;     // never offset more than this (avoid wide-highway shoulders)
// Lateral offset scaled to the road's REAL width (getRoadInfo index 1).
// The returned width is the full model width (incl. shoulders), so we take
// half of it, then subtract half a car plus a margin. Narrow roads / tracks
// and unknown widths fall back to the centerline (offset 0).
private _fnc_laneOffset = {
    params ["_road"];
    private _info  = getRoadInfo _road;
    private _width = if (count _info > 1) then { _info select 1 } else { 0 };
    if (_width <= 0) exitWith { 0 };                       // unknown width -> centerline
    private _maxOff = (_width / 2) - _carHalfWidth - _safetyMargin;
    if (_maxOff < 0.5) exitWith { 0 };                     // too narrow -> centerline
    (_maxOff min _maxLaneOffset) * (selectRandom [-1, 1])  // pick a side
};
for "_i" from 1 to _count do {
    private _class    = selectRandom _pool;
    private _spawnPos = [];
    private _spawnDir = 0;
    {
        private _road = _x;   // capture: nested forEach below would clobber _x
        // (junction segments were already removed from _spawnRoads above)
        private _rdir = [_road] call _fnc_roadDir;
        private _base = getPosATL _road;
        private _perp = [sin (_rdir + 90), cos (_rdir + 90), 0];
        // Offset magnitude/side derived from the actual road width.
        private _off  = [_road] call _fnc_laneOffset;
        // Try the chosen lane, then the opposite lane, then the centerline.
        private _tries = if (_off != 0) then {
            [
                _base vectorAdd (_perp vectorMultiply _off),
                _base vectorAdd (_perp vectorMultiply (-_off)),
                _base
            ]
        } else {
            [_base]
        };
        private _use = [];
        {
            if ([_x, _carFootprint] call _fnc_isClear) exitWith { _use = _x };
        } forEach _tries;
        if !(_use isEqualTo []) exitWith {
            _spawnPos = _use;
            _spawnDir = _rdir + (selectRandom [0, 180]);   // align to road, either way
        };
    } forEach _spawnRoads;
    if (_spawnPos isEqualTo []) then { continue };
    private _veh = createVehicle [_class, _spawnPos, [], 0, "CAN_COLLIDE"];
    if (isNull _veh) then { continue };
    _veh setDir _spawnDir;
    _veh setPosATL _spawnPos;
    _veh setVariable ["GEA_aoId", _aoId, true];
    // Register footprint so later placements avoid this car.
    _obstacles pushBack [_spawnPos, _carFootprint];
    _created pushBack _veh;
};
_aoConfig set ["obstacles", _obstacles];
[format ["%1 / %2 civilian cars parked.", count _created, _count]] call _say;
_created