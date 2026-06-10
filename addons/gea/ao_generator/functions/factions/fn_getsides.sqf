// =====================================================================
// GEA_fnc_getSides
//   Returns the four Arma sides as a [side, displayName] list.
//   Drives the FIRST dropdown in the dialog (replaces the previous
//   hardcoded faction list).
//
//   Usage:
//       _sides = call GEA_fnc_getSides;
//       // [[west, "BLUFOR"], [east, "OPFOR"], [independent, "Independent"], [civilian, "Civilian"]]
// =====================================================================

#include "..\..\script_component.hpp"

[
    [west,        "BLUFOR"],
    [east,        "OPFOR"],
    [independent, "Independent"],
    [civilian,    "Civilian"]
]
