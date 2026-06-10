// =====================================================================
// GEA_fnc_fillBuilding
//   Place units into a building's buildingPos slots. Returns the units
//   that actually got a valid slot.
//
//   Each placed unit:
//     - is teleported to the slot
//     - faces a random direction
//     - has PATH disabled so they hold their post
//     - stance UP (combat-ready); FSM/TARGET/AUTOTARGET kept on so they
//       still shoot back
//
//   Invalid slots are filtered out — any position at world origin, or
//   absurdly far below ground level, is rejected before placement.
//
//   v0.7.0: hard-capped at GEA_GARRISON_MAX_PER_BUILDING (default 4).
//   Garrison groups are meant to be fireteam-sized; a building full of
//   8+ men looked artificial and broke the "small squad per house" feel.
// =====================================================================

#include "..\..\script_component.hpp"

// Hard cap — even if a caller asks for more, we clamp here to keep
// garrison groups fireteam-sized.
#ifndef GEA_GARRISON_MAX_PER_BUILDING
    #define GEA_GARRISON_MAX_PER_BUILDING 4
#endif

params [
    ["_building", objNull, [objNull]],
    ["_units",    [],      [[]]],
    ["_maxCount", 4,       [0]]
];

if (isNull _building) exitWith { [] };
if (_units isEqualTo []) exitWith { [] };

// Clamp the caller-supplied cap so a stray large value can't slip past.
_maxCount = _maxCount min GEA_GARRISON_MAX_PER_BUILDING;
if (_maxCount < 1) exitWith { [] };

// Filter invalid slots. setPos into [0,0,0] sends the unit off the
// terrain entirely; deeply negative Z usually means an unreachable
// basement slot the engine never wires up.
private _slots = (_building buildingPos -1) select {
    !(_x isEqualTo [0,0,0]) && { (_x select 2) > -5 }
};
if (_slots isEqualTo []) exitWith { [] };

// Shuffle so multiple identical buildings don't always fill identically.
_slots = _slots call BIS_fnc_arrayShuffle;

private _placed = [];

{
    if (count _placed >= _maxCount) exitWith {};
    if (count _slots == 0)          exitWith {};
    if (!alive _x)                  then { continue };

    private _slot = _slots deleteAt 0;
    _x setPos _slot;
    _x setDir (random 360);

    _x disableAI "PATH";
    _x setUnitPos "UP";

    _placed pushBack _x;
} forEach _units;

_placed
