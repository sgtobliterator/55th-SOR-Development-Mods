// =====================================================================
// GEA_fnc_validateAOPosition
//   Returns true if a position is suitable for an AO (on land, not
//   inside a no-spawn zone, etc.). Stub for now.
// =====================================================================

#include "..\..\script_component.hpp"

params [["_pos", [0,0,0], [[]], [3]]];

if (surfaceIsWater _pos) exitWith { false };

true
