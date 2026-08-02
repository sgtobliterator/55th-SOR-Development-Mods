// =====================================================================
// GEA_fnc_bake3DEN
//   Eden-editor: turn a placed "Generate Enemy AO" module into REAL,
//   editable editor entities (groups, statics, vehicles) you can drag,
//   reposition and tweak. Patrol behaviour matches Zeus (BIS_fnc_taskPatrol
//   runs from the group's init at mission start).
//
//   Normally invoked automatically by the module itself: tick the module
//   attribute "Generate in editor now" and confirm — see fn_moduleInit's
//   attributesChanged3DEN hook. Can also be called manually:
//       _arrayOfModules call GEA_fnc_bake3DEN;   // bake these modules
//       call GEA_fnc_bake3DEN;                    // bake selected / all
//
//   WHAT IT DOES:
//     - Patrol groups   -> editable editor groups; group init runs
//       BIS_fnc_taskPatrol at mission start (same as Zeus).
//     - Garrison groups -> small editable groups inside buildings.
//     - Static turrets  -> editable static objects, faced outward,
//       crewed at mission start via a self-contained init line.
//     - Vehicle patrols -> editable empty vehicles, crewed at mission
//       start via createVehicleCrew in their init line.
//     - The module is deleted once baked.
//
//   NOTES:
//     - Air patrols are NOT baked (use the runtime/Zeus path for air).
//     - Crew for statics/vehicles appears on Play (init line); infantry
//       are full editor units immediately.
//     - In Eden, setPos/setDir do NOT persist — placement & facing are
//       written with set3DENAttribute.
// =====================================================================

#include "..\..\script_component.hpp"

if (!is3DEN) exitWith {
    diag_log text "[GEA] bake3DEN called outside 3DEN — ignored.";
};

params [["_modsIn", [], [[], objNull]]];

// --- Resolve target modules ------------------------------------------
private _mods = [];
if (_modsIn isEqualType objNull) then {
    if (!isNull _modsIn) then { _mods = [_modsIn] };
} else {
    _mods = _modsIn;
};
// Manual call with nothing passed → selected GEA modules, else all.
if (_mods isEqualTo []) then {
    _mods = (get3DENSelected "object") select { (typeOf _x) == "GEA_Module_GenerateAO" };
};
if (_mods isEqualTo []) then {
    _mods = (all3DENEntities select 0) select { (typeOf _x) == "GEA_Module_GenerateAO" };
};
if (_mods isEqualTo []) exitWith {
    systemChat "[GEA] No 'Generate Enemy AO' module selected or found on the map.";
};

// --- Read an Eden attribute, unwrapping the array form if present -----
private _attr = {
    params ["_ent", "_prop", "_def"];
    private _v = _ent get3DENAttribute _prop;
    if (isNil "_v") exitWith { _def };
    // get3DENAttribute returns the value directly for a single entity, but
    // guard against the wrapped [value] form just in case.
    if (_v isEqualType [] && { (_prop != "position") && (_prop != "rotation") }) then {
        _v = if (count _v > 0) then { _v select 0 } else { _def };
    };
    if (isNil "_v") exitWith { _def };
    _v
};

// --- Expand a group-pool entry into a flat list of unit classnames ----
//   getGroupsForFaction returns [<cfgPath OR [classnames]>, displayName].
private _groupUnits = {
    params ["_entry"];
    private _t = _entry select 0;
    if (_t isEqualType []) exitWith { _t };          // already classnames
    private _units = [];
    {
        private _veh = getText (_x >> "vehicle");
        if (_veh != "") then { _units pushBack _veh };
    } forEach ("true" configClasses _t);
    _units
};

private _totalGroups = 0;
private _totalStatics = 0;
private _totalVehicles = 0;

collect3DENHistory {
{
    private _m = _x;
    private _center = getPosATL _m;

    // --- side ---
    private _sideStr = [_m, "GEA_side", "east"] call _attr;
    private _side = switch (toLower _sideStr) do {
        case "west": { west };
        case "east": { east };
        case "independent": { independent };
        case "guer": { independent };
        case "civilian": { civilian };
        case "civ": { civilian };
        default { east };
    };

    // --- faction (auto-pick first for side if blank) ---
    private _faction = [_m, "GEA_faction", ""] call _attr;
    if (_faction isEqualTo "") then {
        private _facs = [_side] call GEA_fnc_getFactionsForSide;
        if (count _facs > 0) then { _faction = (_facs select 0) select 0 };
    };

    private _radius   = [_m, "GEA_radius",         500] call _attr;
    private _skill    = [_m, "GEA_skill",          0.5] call _attr;
    private _nPatrol  = round ([_m, "GEA_patrolGroups",   3] call _attr);
    private _nGarr    = round ([_m, "GEA_garrisonGroups", 5] call _attr);
    private _nStatic  = round ([_m, "GEA_staticTurrets",  0] call _attr);
    private _nVeh     = round ([_m, "GEA_vehiclePatrols", 1] call _attr);
    private _simple   = [_m, "GEA_simplePathing", false] call _attr;
    private _civFaction      = [_m, "GEA_civFaction",      ""]    call _attr;
    private _nCivPatrol      = round ([_m, "GEA_civPatrol",   0]  call _attr);
    private _nCivGarrison    = round ([_m, "GEA_civGarrison", 0]  call _attr);
    private _nCivCars        = round ([_m, "GEA_civCars",    0]   call _attr);
    private _nMines          = round ([_m, "GEA_mineFields", 0]   call _attr);
    private _showMineMarkers = [_m, "GEA_showMineMarkers", false] call _attr;
    private _nRoadblocks     = round ([_m, "GEA_roadblocks", 0]   call _attr);

    // --- resolve pools (pure config queries — valid in Eden) ---
    private _groupPool = [_side, _faction] call GEA_fnc_getGroupsForFaction;

    private _sideNum = switch (_side) do {
        case east: {0}; case west: {1}; case independent: {2}; case civilian: {3}; default {-1};
    };

    // Reject VR / virtual-entity soldiers (they share real factions).
    private _isVirtualMan = {
        params ["_c", "_cn"];
        ((getText (_c >> "editorSubcategory")) == "EdSubcat_VirtualEntities")
            || { _cn isKindOf "VirtualMan_F" }
            || { toLower _cn find "_vr_" >= 0 }
    };

    // infantry classnames for garrison/crew (faction, then side fallback)
    private _infClasses = [];
    {
        private _c = _x; private _cn = configName _c;
        if (getNumber (_c >> "scope") >= 2 && { _cn isKindOf "CAManBase" }
            && { !([_c, _cn] call _isVirtualMan) }
            && { getText (_c >> "faction") == _faction }) then {
            _infClasses pushBack _cn;
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));
    if (_infClasses isEqualTo []) then {
        {
            private _c = _x; private _cn = configName _c;
            if (getNumber (_c >> "scope") >= 2 && { _cn isKindOf "CAManBase" }
                && { !([_c, _cn] call _isVirtualMan) }
                && { getNumber (_c >> "side") == _sideNum }) then {
                _infClasses pushBack _cn;
            };
        } forEach ("true" configClasses (configFile >> "CfgVehicles"));
    };

    // =============================================================
    //  PATROL GROUPS — editable editor groups (no waypoints)
    // =============================================================
    if (_nPatrol > 0 && { !(_groupPool isEqualTo []) }) then {
        for "_i" from 1 to _nPatrol do {
            private _units = [selectRandom _groupPool] call _groupUnits;
            if (_units isEqualTo []) then { continue };
            private _base = _center getPos [random _radius, random 360];
            private _grp = grpNull;
            private _leadU = objNull;
            {
                private _p = _base vectorAdd [(_forEachIndex mod 4) * 2 - 3, floor (_forEachIndex / 4) * 2, 0];
                private _u = if (isNull _grp) then {
                    create3DENEntity ["Object", _x, _p]
                } else {
                    _grp create3DENEntity ["Object", _x, _p]
                };
                if (isNull _grp) then { _grp = group _u; _leadU = _u };
            } forEach _units;
            if (!isNull _grp) then {
                _totalGroups = _totalGroups + 1;
                // Patrol behaviour identical to Zeus: leader's init kicks
                // off BIS_fnc_taskPatrol around the AO at mission start.
                if (!isNull _leadU) then {
                    // Route via the shared helper so the "Simple Pathing"
                    // toggle behaves identically to the runtime path.
                    private _pInit = format [
                        "if (isServer && {leader group this == this}) then {[group this, getPosATL this, %1, %2] call GEA_fnc_assignPatrol;};",
                        round _radius, _simple
                    ];
                    _leadU set3DENAttribute ["init", _pInit];
                };
            };
        };
    };

    // =============================================================
    //  GARRISON GROUPS — small editable groups inside buildings
    // =============================================================
    if (_nGarr > 0 && { !(_infClasses isEqualTo []) }) then {
        private _buildings = ([_center, _radius] call GEA_fnc_findBuildings) call BIS_fnc_arrayShuffle;
        private _placed = 0;
        while { _placed < _nGarr && { count _buildings > 0 } } do {
            private _b = _buildings deleteAt 0;
            private _slots = (_b buildingPos -1) select { !(_x isEqualTo [0,0,0]) && { (_x select 2) > -5 } };
            if (count _slots < 1) then { continue };
            private _per = ((2 + floor random 3) min (count _slots)) max 1;
            private _grp = grpNull;
            for "_k" from 0 to (_per - 1) do {
                private _p = _slots select _k;
                private _cls = selectRandom _infClasses;
                private _u = if (isNull _grp) then {
                    create3DENEntity ["Object", _cls, _p]
                } else {
                    _grp create3DENEntity ["Object", _cls, _p]
                };
                if (isNull _grp) then { _grp = group _u };
            };
            if (!isNull _grp) then {
                _placed = _placed + 1;
                _totalGroups = _totalGroups + 1;
            };
        };
    };

    // =============================================================
    //  STATIC TURRETS — editable objects, faced outward, init-crewed
    // =============================================================
    if (_nStatic > 0) then {
        // armed StaticWeapon pool (faction first, then side) — same
        // "real turret" filter as the runtime spawner.
        private _isTurret = {
            params ["_c"];
            private _tc = _c >> "Turrets";
            if (!isClass _tc) exitWith { false };
            private _ok = false;
            { if (count (getArray (_x >> "weapons")) > 0 || { getText (_x >> "weapon") != "" }) exitWith { _ok = true }; }
                forEach configProperties [_tc, "isClass _x", true];
            _ok
        };
        private _facStat = []; private _sideStat = [];
        {
            private _c = _x; private _cn = configName _c;
            if (getNumber (_c >> "scope") >= 2 && { _cn isKindOf "StaticWeapon" } && { [_c] call _isTurret }) then {
                if (getText (_c >> "faction") == _faction) then { _facStat pushBack _cn };
                if (getNumber (_c >> "side") == _sideNum) then { _sideStat pushBack _cn };
            };
        } forEach ("true" configClasses (configFile >> "CfgVehicles"));
        private _statPool = if (count _facStat > 0) then { _facStat } else { _sideStat };

        if (!(_statPool isEqualTo []) && { !(_infClasses isEqualTo []) }) then {
            private _sideText = str _side;   // "WEST"/"EAST"/...
            for "_i" from 1 to _nStatic do {
                private _dist = (0.5 + random 0.45) * _radius;
                private _pos  = _center getPos [_dist, random 360];
                private _cls  = selectRandom _statPool;
                private _gunner = [_infClasses] call GEA_fnc_pickTurretCrew;
                private _obj = create3DENEntity ["Object", _cls, _pos];
                if (!isNull _obj) then {
                    private _dir = (_center getDir _pos) + (random 40 - 20);
                    _obj set3DENAttribute ["rotation", [0, 0, _dir]];
                    // self-crew at mission start
                    private _init = format [
                        "if (isServer) then {private _g = createGroup [%1, true]; private _u = _g createUnit ['%2', getPosATL this, [], 0, 'CAN_COLLIDE']; _u moveInGunner this; _u setSkill %3;};",
                        _sideText, _gunner, _skill
                    ];
                    _obj set3DENAttribute ["init", _init];
                    _totalStatics = _totalStatics + 1;
                };
            };
        };
    };

    // =============================================================
    //  VEHICLE PATROLS — editable empty vehicles, init-crewed
    // =============================================================
    if (_nVeh > 0) then {
        private _facVeh = []; private _sideVeh = [];
        {
            private _c = _x; private _cn = configName _c;
            if (getNumber (_c >> "scope") >= 2
                && { (_cn isKindOf "Car") || (_cn isKindOf "Tank") }
                && { !(_cn isKindOf "StaticWeapon") } && { !(_cn isKindOf "ParachuteBase") }) then {
                if (getText (_c >> "faction") == _faction) then { _facVeh pushBack _cn };
                if (getNumber (_c >> "side") == _sideNum) then { _sideVeh pushBack _cn };
            };
        } forEach ("true" configClasses (configFile >> "CfgVehicles"));
        private _vehPool = if (count _facVeh > 0) then { _facVeh } else { _sideVeh };

        if (!(_vehPool isEqualTo [])) then {
            for "_i" from 1 to _nVeh do {
                private _pos = _center getPos [random _radius, random 360];
                private _cls = selectRandom _vehPool;
                private _obj = create3DENEntity ["Object", _cls, _pos];
                if (!isNull _obj) then {
                    _obj set3DENAttribute ["rotation", [0, 0, random 360]];
                    private _init = format [
                        "if (isServer) then {createVehicleCrew this; {_x setSkill %1} forEach (crew this);};",
                        _skill
                    ];
                    _obj set3DENAttribute ["init", _init];
                    _totalVehicles = _totalVehicles + 1;
                };
            };
        };
    };

    // =============================================================
    //  CIVILIANS — editable individual civ units (wander + in-house)
    // =============================================================
    if (_nCivPatrol > 0 || _nCivGarrison > 0) then {
        // Civ man pool: faction first, civilian-side (3) fallback.
        private _civMenFac = []; private _civMenSide = [];
        {
            private _c = _x; private _cn = configName _c;
            if (getNumber (_c >> "scope") >= 2 && { _cn isKindOf "CAManBase" }
                && { !([_c, _cn] call _isVirtualMan) }) then {
                if (_civFaction != "" && { getText (_c >> "faction") == _civFaction }) then { _civMenFac pushBack _cn };
                if (getNumber (_c >> "side") == 3) then { _civMenSide pushBack _cn };
            };
        } forEach ("true" configClasses (configFile >> "CfgVehicles"));
        private _civPool = if (count _civMenFac > 0) then { _civMenFac } else { _civMenSide };

        if (!(_civPool isEqualTo [])) then {
            // PATROL civs — wander on open ground (2-wp + cycle at start).
            private _wanderInit = format [
                "this setBehaviour 'SAFE'; if (isServer && {leader group this == this}) then {private _g = group this; private _c = getPosATL this; for '_k' from 1 to 2 do {private _w = _g addWaypoint [_c getPos [%1 + random %1, random 360], 0]; _w setWaypointType 'MOVE'; _w setWaypointBehaviour 'SAFE'; _w setWaypointSpeed 'LIMITED';}; (_g addWaypoint [_c, 0]) setWaypointType 'CYCLE';};",
                round (_radius / 4)
            ];
            for "_i" from 1 to _nCivPatrol do {
                private _pos = _center getPos [random _radius, random 360];
                private _u = create3DENEntity ["Object", selectRandom _civPool, _pos];
                if (!isNull _u) then {
                    _u set3DENAttribute ["init", _wanderInit];
                    _totalGroups = _totalGroups + 1;
                };
            };

            // GARRISON civs — placed standing in building positions.
            if (_nCivGarrison > 0) then {
                private _bs = ([_center, _radius] call GEA_fnc_findBuildings) call BIS_fnc_arrayShuffle;
                private _slots = [];
                { { if (!(_x isEqualTo [0,0,0]) && { (_x select 2) > -5 }) then { _slots pushBack _x }; } forEach (_x buildingPos -1); } forEach _bs;
                _slots = _slots call BIS_fnc_arrayShuffle;
                private _placed = 0;
                while {_placed < _nCivGarrison && {count _slots > 0}} do {
                    private _pos = _slots deleteAt 0;
                    private _u = create3DENEntity ["Object", selectRandom _civPool, _pos];
                    if (!isNull _u) then {
                        _u set3DENAttribute ["init", "this setBehaviour 'SAFE'; this setUnitPos 'UP';"];
                        _placed = _placed + 1;
                        _totalGroups = _totalGroups + 1;
                    };
                };
            };
        };
    };

    // =============================================================
    //  CIVILIAN CARS — editable empty parked vehicles
    // =============================================================
    if (_nCivCars > 0) then {
        private _carFac = []; private _carSide = [];
        {
            private _c = _x; private _cn = configName _c;
            if (getNumber (_c >> "scope") >= 2 && { _cn isKindOf "Car" }
                && { !(_cn isKindOf "StaticWeapon") } && { !(_cn isKindOf "ParachuteBase") }
                && { !(_cn isKindOf "Kart_01_base_F") }) then {
                if (_civFaction != "" && { getText (_c >> "faction") == _civFaction }) then { _carFac pushBack _cn };
                if (getNumber (_c >> "side") == 3) then { _carSide pushBack _cn };
            };
        } forEach ("true" configClasses (configFile >> "CfgVehicles"));
        private _carPool = if (count _carFac > 0) then { _carFac } else { _carSide };

        private _carRoads = (_center nearRoads _radius) call BIS_fnc_arrayShuffle;
        if (!(_carPool isEqualTo []) && { !(_carRoads isEqualTo []) }) then {
            for "_i" from 1 to _nCivCars do {
                private _rd   = selectRandom _carRoads;
                private _conn = roadsConnectedTo _rd;
                private _rdir = if (count _conn > 0) then { (getPosATL _rd) getDir (getPosATL (_conn select 0)) } else { direction _rd };
                // Offset onto a lane (perpendicular), not the centerline.
                private _off  = selectRandom [-3.25, 3.25];
                private _pos  = (getPosATL _rd) vectorAdd ([sin (_rdir + 90), cos (_rdir + 90), 0] vectorMultiply _off);
                private _dir  = _rdir + (selectRandom [0, 180]);
                private _cls = selectRandom _carPool;
                private _obj = create3DENEntity ["Object", _cls, _pos];
                if (!isNull _obj) then {
                    _obj set3DENAttribute ["rotation", [0, 0, _dir]];
                    _totalVehicles = _totalVehicles + 1;
                };
            };
        };
    };

    // =============================================================
    //  MINEFIELDS — editable mine objects on the perimeter
    // =============================================================
    if (_nMines > 0) then {
        // Real AP/AT land mines only — same exclusion list as the runtime
        // spawner (no training, charges, IEDs, sensor/targeting, naval).
        private _mineExclude = ["train","practice","dummy","decoy","naval","water","sea","ied","satchel","demo","charge","c4","slam","designator","target"];
        private _minePool = [];
        {
            private _c = _x; private _cn = configName _c;
            if (getNumber (_c >> "scope") >= 2 && { _cn isKindOf "MineBase" }) then {
                private _lc = toLower _cn;
                private _ld = toLower getText (_c >> "displayName");
                if ((_mineExclude findIf { (_lc find _x >= 0) || (_ld find _x >= 0) }) < 0) then {
                    _minePool pushBack _cn;
                };
            };
        } forEach ("true" configClasses (configFile >> "CfgVehicles"));

        if (!(_minePool isEqualTo [])) then {
            for "_f" from 1 to _nMines do {
                private _fieldPos = _center getPos [(0.5 + random 0.45) * _radius, random 360];
                private _fieldR   = 12 + random 20;
                private _mc       = ((round (_fieldR * 0.7)) max 6) min 25;
                for "_k" from 1 to _mc do {
                    private _mp  = _fieldPos getPos [random _fieldR, random 360];
                    private _cls = selectRandom _minePool;
                    create3DENEntity ["Object", _cls, _mp];
                };
            };
        };
    };

    // =============================================================
    //  ROADBLOCKS — editable wire + sandbag tower + held guards
    // =============================================================
    if (_nRoadblocks > 0) then {
        private _wireCls    = "Land_Razorwire_F";
        private _bunkerCls  = "Land_BagBunker_Small_F";
        private _sandbagCls = "Land_BagFence_Long_F";
        if (!isClass (configFile >> "CfgVehicles" >> _wireCls))    then { _wireCls    = "Land_BagFence_Long_F" };
        if (!isClass (configFile >> "CfgVehicles" >> _bunkerCls))  then { _bunkerCls  = "Land_BagBunker_Large_F" };
        if (!isClass (configFile >> "CfgVehicles" >> _sandbagCls)) then { _sandbagCls = "Land_BagFence_Short_F" };

        private _roads = (_center nearRoads _radius) call BIS_fnc_arrayShuffle;
        private _outer = _roads select { (_center distance2D (getPosATL _x)) > (0.5 * _radius) };
        if (_outer isEqualTo []) then { _outer = _roads };

        private _done = 0;
        {
            if (_done >= _nRoadblocks) exitWith {};
            private _road = _x;
            private _rPos = getPosATL _road;
            private _conn = roadsConnectedTo _road;
            private _rDir = if (count _conn > 0) then { _rPos getDir (getPosATL (_conn select 0)) } else { direction _road };
            private _fwd = [sin _rDir, cos _rDir, 0];
            private _rgt = [sin (_rDir + 90), cos (_rDir + 90), 0];
            private _mk = {
                params ["_cls", "_along", "_across", "_dir"];
                private _p = _rPos vectorAdd (_fwd vectorMultiply _along) vectorAdd (_rgt vectorMultiply _across);
                private _o = create3DENEntity ["Object", _cls, _p];
                if (!isNull _o) then { _o set3DENAttribute ["rotation", [0, 0, _dir]] };
                _o
            };
            // Simple layout — 3 wire belts across the road, a sandbag wall
            // beside each, a bunker on the left shoulder. Mirrors the
            // runtime spawner (fn_spawnRoadblock).
            [_wireCls,  6, -1, _rDir] call _mk;
            [_wireCls,  0,  1, _rDir] call _mk;
            [_wireCls, -6, -1, _rDir] call _mk;
            [_sandbagCls,  4.5, 2, _rDir + 90] call _mk;
            [_sandbagCls, -1.5, 2, _rDir + 90] call _mk;
            [_sandbagCls, -7.5, 2, _rDir + 90] call _mk;
            [_bunkerCls, 3, -6, _rDir + 90] call _mk;
            _totalStatics = _totalStatics + 7;

            // Guards (2-3), own group, HOLD at the block.
            if (!(_infClasses isEqualTo [])) then {
                private _grp = grpNull;
                private _ng = 2 + floor random 2;
                for "_g" from 1 to _ng do {
                    private _gp  = _rPos getPos [3 + random 4, _rDir + 90 + (random 120 - 60)];
                    private _cls = [_infClasses] call GEA_fnc_pickTurretCrew;
                    if (_cls == "") then { _cls = selectRandom _infClasses };
                    private _u = if (isNull _grp) then { create3DENEntity ["Object", _cls, _gp] } else { _grp create3DENEntity ["Object", _cls, _gp] };
                    if (isNull _grp) then { _grp = group _u };
                };
                if (!isNull _grp) then { _totalGroups = _totalGroups + 1 };
            };
            _done = _done + 1;
        } forEach _outer;
    };

    // --- consume the module ---
    delete3DENEntities [_m];

} forEach _mods;
};

systemChat format ["[GEA] Baked %1 module(s): %2 groups, %3 static turrets, %4 vehicles. Add LAMBS/waypoints as desired.",
    count _mods, _totalGroups, _totalStatics, _totalVehicles];
diag_log text format ["[GEA] bake3DEN done — %1 groups, %2 statics, %3 vehicles from %4 module(s).",
    _totalGroups, _totalStatics, _totalVehicles, count _mods];
