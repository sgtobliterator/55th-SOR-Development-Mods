// =====================================================================
// GEA_fnc_spawnPatrolGroup
//   Spawns one infantry patrol group inside the AO and assigns it a
//   randomized patrol task. Returns the group (grpNull on failure).
//
//   Picks a group template from _aoConfig["groupPool"], which is
//   pre-resolved by fn_generateAO via fn_getGroupsForFaction.
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith { grpNull };

params [["_aoConfig", createHashMap, [createHashMap]]];

private _center    = _aoConfig get "center";
private _radius    = _aoConfig get "radius";
private _side      = _aoConfig get "side";
private _skill     = _aoConfig get "skill";
private _groupPool = _aoConfig getOrDefault ["groupPool", []];

if (_groupPool isEqualTo []) exitWith { grpNull };

// --- Pick a spawn position inside the AO, on land, with clearance ---
private _spawnPos = [];
for "_try" from 1 to 24 do {
    private _candidate = _center getPos [random _radius, random 360];
    if (!surfaceIsWater _candidate) then {
        // Reject positions stuck inside a building/object.
        private _blocked = (nearestObjects [_candidate, ["Building","House","Wall"], 2]) isNotEqualTo [];
        if (!_blocked) exitWith {
            _spawnPos = ASLToAGL (AGLToASL _candidate);   // normalize height
        };
    };
};
if (_spawnPos isEqualTo []) exitWith {
    diag_log text "[GEA] spawnPatrolGroup: couldn't find a clear spawn position. Skipping.";
    grpNull
};

// --- Spawn the group from a random template ---
// _groupEntry is [<configPath OR [classnames]>, displayName] — both
// forms are accepted by BIS_fnc_spawnGroup as the "type" argument.
private _groupEntry = selectRandom _groupPool;
private _groupType  = _groupEntry select 0;
private _grp = [_spawnPos, _side, _groupType] call BIS_fnc_spawnGroup;

if (isNull _grp) exitWith {
    diag_log text format ["[GEA] BIS_fnc_spawnGroup returned null for %1 (side=%2)", _groupType, _side];
    grpNull
};

// --- Skill + patrol task ---
{
    _x setSkill _skill;
    _x setVariable ["GEA_aoId", _aoConfig get "id", true];
} forEach (units _grp);
_grp setVariable ["GEA_aoId", _aoConfig get "id", true];

// Route the group. "Simple Pathing" (config key) swaps the dynamic
// BIS_fnc_taskPatrol for a cheap 2-waypoint + cycle loop.
private _simple = _aoConfig getOrDefault ["simplePathing", false];
[_grp, _center, _radius, _simple] call GEA_fnc_assignPatrol;

_grp
