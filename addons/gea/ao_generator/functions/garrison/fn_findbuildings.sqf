// =====================================================================
// GEA_fnc_findBuildings
//   Returns enterable buildings within radius. A building counts as
//   enterable iff it has at least one buildingPos slot.
// =====================================================================

#include "..\..\script_component.hpp"

params [
    ["_center", [0,0,0], [[]], [3]],
    ["_radius", 200,     [0]]
];

// "House" covers most enterable structures. We don't include "Building"
// because that base also covers walls, fences, lamp posts, etc.
private _candidates = nearestObjects [_center, ["House"], _radius];

_candidates select { (count (_x buildingPos -1)) > 0 }
