#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Garrisons positions in a building with one unit each. All units go
 * into a SINGLE group (deleteWhenEmpty / garbageCollectGroup). Adapted
 * from ZEI's fn_garrisonUnit / fn_ui_garrisonBuilding
 * (zei/functions/garrisonBuilding/).
 *
 * Two modes:
 *   - Military (default): 8-way raycast outward facing, exposure-
 *     dependent kneel/prone, AWARE/YELLOW baseline, role GUARD.
 *   - Civilian (_passive=true): random facing, AUTO stance,
 *     SAFE/BLUE baseline, role CIV_GARRISON. "At home", not tactical.
 *
 * Per design: consumes one Guard / Resident slot but produces N units,
 * where N = count (_building buildingPos -1), capped at _cap.
 *
 * 3DEN grouping note: create3DENEntity in its unary form always creates a
 * fresh group for the new unit. To force all garrison units into one group
 * we seed a temp unit (which spawns a group), reuse `group _tempSeedUnit`
 * for the actual spawns via the binary form, then delete the seed.
 *
 * Arguments:
 * 0: Building <OBJECT>
 * 1: Zone id <STRING>
 * 2: Unit pool of classnames <ARRAY>
 * 3: Skill cap <NUMBER>
 * 4: Group side (runtime only; 3DEN ignores) <SIDE>
 * 5: Max units per building (optional, default GARRISON_MAX_UNITS_PER_BUILDING) <NUMBER>
 * 6: Passive (civilian) baseline (optional, default false) <BOOL>
 *
 * Return Value:
 * Created units; empty if building has no positions <ARRAY>
 *
 * Example:
 * [_building, "zone_1", _pool, 0.2, east] call digii_ambient_agents_fnc_garrisonBuilding
 * [_building, "zone_1", _pool, 0.2, civilian, 3, true] call digii_ambient_agents_fnc_garrisonBuilding
 *
 * Public: No
 */

params [
    "_building", "_zoneId", "_unitPool", "_skillCap", "_side",
    ["_cap", GARRISON_MAX_UNITS_PER_BUILDING, [0]],
    ["_passive", false, [false]]
];

private _bldPos = _building buildingPos -1;
if (_bldPos isEqualTo []) exitWith {[]};

// Cap garrison size. Some large buildings expose 40+ positions; filling all
// of them produces unrealistic densities and inflates the actual unit count
// far past the slot budget. Shuffle then take first N so the kept positions
// are spatially varied, not always the lowest-indexed ones.
if (count _bldPos > _cap) then {
    _bldPos = _bldPos call BIS_fnc_arrayShuffle;
    _bldPos resize _cap;
};

private _grp = if (is3DEN) then { grpNull } else { createGroup [_side, true] };

// Picks facing direction + stance for a single garrisoned unit.
// Ported from ZEI's _setDirStance (fn_garrisonUnit.sqf).
private _orientUnit = {
    params ["_unit", "_bld"];

    private _eyePos = eyePos _unit;

    // If the unit has open sky directly overhead (rooftop / courtyard), kneel.
    if (count (lineIntersectsWith [_eyePos, (_eyePos vectorAdd [0, 0, 10])] select { _x isKindOf "Building" }) < 1) then {
        if (is3DEN) then { _unit set3DENAttribute ["unitPos", 1] } else { _unit setUnitPos "MIDDLE" };
        _eyePos = eyePos _unit;
    };

    private _p1 = []; // Facing outward, no wall within 10m
    private _p2 = []; // Facing inward, no wall within 10m
    private _p3 = []; // Wall within 10m
    private _p4 = []; // Wall within 3m (face-the-wall)
    private _emptyCount = 0;

    for "_dir" from (getDir _bld) to ((getDir _bld) + 359) step 45 do {
        if (lineIntersectsWith [_eyePos,[_eyePos,3,_dir] call BIS_fnc_relPos] select {_x isKindOf "Building"} isNotEqualTo []) then {
            _p4 pushBack _dir;
        } else {
            if (lineIntersectsWith [_eyePos,[_eyePos,10,_dir] call BIS_fnc_relPos] select {_x isKindOf "Building"} isNotEqualTo []) then {
                _p3 pushBack _dir;
            } else {
                if (abs ((_eyePos getDir _bld) - _dir) >= 120) then {
                    _p1 pushBack _dir;
                } else {
                    _p2 pushBack _dir;
                };
                _emptyCount = _emptyCount + 1;
            };
        };
    };

    private _finalDir = -1;
    {
        if (_x isNotEqualTo []) then { _finalDir = selectRandom _x };
        if (_finalDir >= 0) exitWith {};
    } forEach [_p1, _p2, _p3, _p4];

    if (_finalDir >= 0) then {
        if (is3DEN) then {
            _unit set3DENAttribute ["rotation", [0, 0, _finalDir]];
        } else {
            _unit doWatch (_unit getPos [100, _finalDir]);
            _unit setDir _finalDir;
        };
    };

    // Semi-exposed: kneel (occasionally).
    if (_emptyCount >= 5 && {random 1 > 0.2}) then {
        if (is3DEN) then { _unit set3DENAttribute ["unitPos", 1] } else { _unit setUnitPos "MIDDLE" };
    };

    // Very exposed: kneel or prone.
    if (_emptyCount >= 7) then {
        if (random 1 > 0.2) then {
            if (is3DEN) then { _unit set3DENAttribute ["unitPos", 1] } else { _unit setUnitPos "MIDDLE" };
        } else {
            if (is3DEN) then { _unit set3DENAttribute ["unitPos", 2] } else { _unit setUnitPos "DOWN" };
        };
    };
};

private _units = [];
private _tempSeedUnit = objNull;

private _doSpawn = {
    if (is3DEN) then {
        // Seed a group: in 3DEN every unary create3DENEntity makes a NEW
        // group, so we make one throwaway unit, grab its group, and use the
        // binary form for the real spawns. Deleted after the loop.
        _tempSeedUnit = create3DENEntity ["Object", _unitPool select 0, [0, 0, 0]];
        if (!isNull _tempSeedUnit) then { _grp = group _tempSeedUnit };
    };

    {
        private _pos = _x;
        private _cls = selectRandom _unitPool;

        private _entity = if (is3DEN) then {
            // Binary form puts the new entity in _grp instead of a fresh group.
            private _e = _grp create3DENEntity ["Object", _cls, [0, 0, 0]];
            if (!isNull _e) then {
                _e set3DENAttribute ["position", _pos];
            };
            _e
        } else {
            private _u = _grp createUnit [_cls, _pos, [], 0, "NONE"];
            if (!isNull _u) then { _u setPosATL _pos };
            _u
        };

        if (!isNull _entity) then {
            if (_passive) then {
                // Civilian "at home" -- random facing, AUTO stance.
                private _dir = floor (random 360);
                if (is3DEN) then {
                    _entity set3DENAttribute ["rotation", [0, 0, _dir]];
                } else {
                    _entity setDir _dir;
                };
            } else {
                [_entity, _building] call _orientUnit;
            };

            // Role tag: civilian residents get ROLE_CIV_GARRISON, military
            // guards get ROLE_GUARD. Set on the unit at runtime and also
            // stamped into the 3DEN Init attribute so the role persists
            // through mission.sqm save/load on Eden-placed units.
            private _roleTag = if (_passive) then { ROLE_CIV_GARRISON } else { ROLE_GUARD };

            // Both modes keep PATH off (stay in the building).
            // Military: AWARE/YELLOW (fire at known enemies on sight).
            // Civilian: SAFE/BLUE (passive, never engage).
            // For 3DEN civilians (_passive), append the threat-system
            // self-init call to the Init stamp -- module logic
            // setVariables don't survive mission.sqm save/load, but the
            // per-unit Init attribute does.
            if (is3DEN) then {
                private _initStr = format [
                    "this setVariable ['digii_ambient_role', '%1']; this disableAI 'PATH';",
                    _roleTag
                ];
                if (_passive) then {
                    // Civilian residents: kill danger.fsm so our threat system
                    // owns motor state; self-init threat EHs at preview.
                    _initStr = _initStr + " this disableAI 'AUTOCOMBAT'; this disableAI 'FSM'; [this] call digii_ambient_agents_fnc_initCivilianThreat;";
                };
                _entity set3DENAttribute ["Init", _initStr];
            } else {
                _entity disableAI "PATH";
            };

            if (_passive) then {
                _entity setBehaviour "SAFE";
                _entity setCombatMode "BLUE";
                // Mirrors the 3DEN Init stamp above for runtime-spawned residents.
                _entity disableAI "AUTOCOMBAT";
                _entity disableAI "FSM";
            } else {
                _entity setBehaviour "AWARE";
                _entity setCombatMode "YELLOW";
            };
            _entity setSkill _skillCap;
            _entity setVariable ["digii_ambient_zoneId", _zoneId];
            _entity setVariable ["digii_ambient_role", _roleTag];

            // Civilian threat-system hookup. Runtime only; 3DEN editor
            // units re-initialize at preview when the spawn pipeline reruns.
            if (_passive && {!is3DEN}) then {
                [_entity] call FUNC(initCivilianThreat);
            };

            _units pushBack _entity;
        };
    } forEach _bldPos;

    if (is3DEN && {!isNull _tempSeedUnit}) then {
        // Auto-clean the group when its last unit dies / is removed.
        _grp set3DENAttribute ["garbageCollectGroup", true];
        delete3DENEntities [_tempSeedUnit];
    };
};

// Bundle the whole sequence into one 3DEN undo step; runtime just calls it.
if (is3DEN) then { collect3DENHistory _doSpawn } else { call _doSpawn };

INFO_2("Garrisoned %1 units in building %2",count _units,_building);

_units
