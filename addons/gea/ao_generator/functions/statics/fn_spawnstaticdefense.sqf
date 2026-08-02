// =====================================================================
// GEA_fnc_spawnStaticDefense
//   Spawns ONE manned static weapon (turret) inside the AO and points
//   it OUTWARD from the AO centre, so a count of them forms a rough
//   defensive ring around the objective.
//
//   Mirrors the spawn philosophy of fn_spawnVehiclePatrol:
//     - Two-tier pool: faction-matched statics first (keeps the theme),
//       side-matched statics as fallback.
//     - Random class pick from the chosen pool.
//     - Clear, non-water, non-overlapping spawn position, biased toward
//       the OUTER ring of the AO so turrets sit on the perimeter rather
//       than the middle.
//     - Manned from the infantryClasses cache (resolved once in
//       fn_generateAO). No crew → the static is deleted and we return
//       null so the orchestrator doesn't count it.
//
//   "Static weapon" = anything isKindOf "StaticWeapon": HMG / GMG nests,
//   AA / AT launchers, mortars, autocannon emplacements, etc. The pick
//   is random across whatever the faction/side provides, per the design
//   ("random picked from the category from the faction").
//
//   Returns: [_static, _crewGroup]  ([objNull, grpNull] on failure)
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith { [objNull, grpNull] };

params [["_aoConfig", createHashMap, [createHashMap]]];

private _center  = _aoConfig get "center";
private _radius  = _aoConfig get "radius";
private _side    = _aoConfig get "side";
private _faction = _aoConfig get "faction";
private _skill   = _aoConfig get "skill";
private _aoId    = _aoConfig get "id";

private _say = {
    params ["_msg"];
    diag_log text format ["[GEA] static: %1", _msg];
};

// CfgVehicles "side" numeric (same convention used elsewhere).
private _sideNum = switch (_side) do {
    case east:        { 0 };
    case west:        { 1 };
    case independent: { 2 };
    case civilian:    { 3 };
    default           { -1 };
};

// ---------------------------------------------------------------------
// "Real turret" test.
//   isKindOf "StaticWeapon" is too broad: in vanilla (and many mods) it
//   also catches Taru transport / bench / cargo / fuel / repair pods and
//   other emplaced props that inherit the StaticWeapon base but carry NO
//   weapon. A genuine turret has at least one Turret entry with a
//   non-empty weapons[] (or a legacy `weapon = "..."`). Filtering on that
//   keeps HMG / GMG / AA / AT / mortar / grenade emplacements and drops
//   the pods and weaponless oddities.
// ---------------------------------------------------------------------
private _fnc_isUsableTurret = {
    params ["_cfg"];
    private _turretsCfg = _cfg >> "Turrets";
    if (!isClass _turretsCfg) exitWith { false };
    private _ok = false;
    {
        if (count (getArray (_x >> "weapons")) > 0
            || { (getText (_x >> "weapon")) != "" }
        ) exitWith { _ok = true };
    } forEach configProperties [_turretsCfg, "isClass _x", true];
    _ok
};

// ---------------------------------------------------------------------
// Build pools — iterate CfgVehicles once, bucket *armed* StaticWeapon
// classes into faction / side. scope >= 2 (public) only.
// ---------------------------------------------------------------------
private _factionStatics = [];
private _sideStatics    = [];
private _rejectedNoWeapon = 0;

{
    private _cfg   = _x;
    private _class = configName _cfg;

    if (getNumber (_cfg >> "scope") >= 2
        && { _class isKindOf "StaticWeapon" }
    ) then {
        if (!([_cfg] call _fnc_isUsableTurret)) then {
            // Weaponless StaticWeapon (pod / prop) — skip it.
            _rejectedNoWeapon = _rejectedNoWeapon + 1;
        } else {
            private _vehSide    = getNumber (_cfg >> "side");
            private _vehFaction = getText   (_cfg >> "faction");

            if (_vehFaction == _faction) then { _factionStatics pushBack _class };
            if (_vehSide    == _sideNum)  then { _sideStatics    pushBack _class };
        };
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

[format ["rejected %1 weaponless StaticWeapon classes (pods/props).", _rejectedNoWeapon]] call _say;

// Tier select: faction first if it has ANY static, otherwise side.
private _pool     = [];
private _poolTier = "";
if (count _factionStatics > 0) then {
    _pool     = _factionStatics;
    _poolTier = "faction";
} else {
    if (count _sideStatics > 0) then {
        _pool     = _sideStatics;
        _poolTier = "side-fallback";
    };
};

[format ["pool tier=%1 faction=%2 side=%3", _poolTier, count _factionStatics, count _sideStatics]] call _say;
[format ["usable turret pool (%1): %2", count _pool, _pool]] call _say;

if (_pool isEqualTo []) exitWith {
    ["NO static weapons found for faction OR side — skipping."] call _say;
    [objNull, grpNull]
};

private _class = selectRandom _pool;

// ---------------------------------------------------------------------
// Spawn position — biased to the outer ring (50–95% of radius) so the
// turrets form a perimeter. Reject water, building/wall/static overlap,
// and positions too close to a previously placed static.
// ---------------------------------------------------------------------
private _clearance  = ((sizeOf _class) max 3) + 1;
private _minSpacing = 20;
private _prior      = _aoConfig getOrDefault ["staticSpawns", []];
private _obstacles  = _aoConfig getOrDefault ["obstacles", []];   // shared registry

private _isClear = {
    params ["_p"];
    if (surfaceIsWater _p) exitWith { false };
    if (!((nearestObjects [_p, ["Building","House","Wall","Static"], _clearance]) isEqualTo [])) exitWith {
        false
    };
    private _tooClose = false;
    {
        if ((_p distance2D _x) < _minSpacing) exitWith { _tooClose = true };
    } forEach _prior;
    if (_tooClose) exitWith { false };
    // Don't sit on top of another placed object (vehicle, car, roadblock).
    (_obstacles findIf { (_p distance2D (_x select 0)) < ((_x select 1) + _clearance) }) < 0
};

private _spawnPos = [];
for "_try" from 1 to 48 do {
    private _dist      = (0.5 + (random 0.45)) * _radius;   // outer ring
    private _candidate = _center getPos [_dist, random 360];
    if ([_candidate] call _isClear) exitWith { _spawnPos = _candidate };
};

if (_spawnPos isEqualTo []) exitWith {
    [format ["no clear spawn position (clearance %1m, spacing %2m from %3 prior).",
        _clearance, _minSpacing, count _prior]] call _say;
    [objNull, grpNull]
};

_prior pushBack _spawnPos;
_aoConfig set ["staticSpawns", _prior];
// Reserve footprint in the shared registry so other placements avoid it.
_obstacles pushBack [_spawnPos, _clearance];
_aoConfig set ["obstacles", _obstacles];

// ---------------------------------------------------------------------
// Create the static and face it OUTWARD from the AO centre. A small
// random jitter (±20°) keeps a ring from looking unnaturally uniform.
// ---------------------------------------------------------------------
private _static = createVehicle [_class, _spawnPos, [], 0, "CAN_COLLIDE"];
if (isNull _static) exitWith {
    [format ["createVehicle returned null for %1", _class]] call _say;
    [objNull, grpNull]
};

private _outwardDir = (_center getDir _spawnPos) + (random 40 - 20);
_static setDir _outwardDir;
_static setPos _spawnPos;

// ---------------------------------------------------------------------
// Man it. Use the faction/side infantry cache resolved by the
// orchestrator. moveInGunner so the weapon is actually crewed.
// ---------------------------------------------------------------------
private _infantryClasses = _aoConfig getOrDefault ["infantryClasses", []];
if (_infantryClasses isEqualTo []) exitWith {
    ["no infantry classes cached to crew the static — deleting it."] call _say;
    deleteVehicle _static;
    [objNull, grpNull]
};

// Pick a sensible gunner: prefer a rifleman; never use pilots / divers /
// vehicle crewmen (they make no sense manning a turret). Fall back to any
// non-specialist ground infantry, then to anything as a last resort.
private _gunnerClass = [_infantryClasses] call GEA_fnc_pickTurretCrew;

private _crewGroup = createGroup [_side, true];
private _gunner    = _crewGroup createUnit [_gunnerClass, _spawnPos, [], 0, "NONE"];

if (isNull _gunner) exitWith {
    ["gunner creation failed — deleting static."] call _say;
    deleteVehicle _static;
    if (!isNull _crewGroup) then { deleteGroup _crewGroup };
    [objNull, grpNull]
};

_gunner setSkill _skill;
_gunner moveInGunner _static;

// If the gunner didn't actually take the gunner seat (some statics have
// odd turret configs), fall back to assignAsGunner + orderGetIn.
if (isNull (gunner _static)) then {
    _gunner assignAsGunner _static;
    [_gunner] orderGetIn true;
};

_crewGroup setBehaviour "COMBAT";
_crewGroup setCombatMode "RED";

// Tag for cleanup / Zeus registration (registerCleanup re-tags too, but
// tagging here keeps the static consistent with the other spawners).
_static    setVariable ["GEA_aoId", _aoId, true];
_gunner    setVariable ["GEA_aoId", _aoId, true];
_crewGroup setVariable ["GEA_aoId", _aoId, true];

[format ["%1 placed at %2m, facing %3 (tier=%4)",
    _class, round (_center distance2D _spawnPos), round _outwardDir, _poolTier]] call _say;

[_static, _crewGroup]
