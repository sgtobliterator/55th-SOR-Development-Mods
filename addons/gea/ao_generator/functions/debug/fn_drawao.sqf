// =====================================================================
// GEA_fnc_drawAO
//   Draws the AO radius + patrol markers on the curator's map. Useful
//   while iterating; ship behind a debug flag.
// =====================================================================

#include "..\..\script_component.hpp"

params [["_aoConfig", createHashMap, [createHashMap]]];

// TODO: create local markers (radius circle, group icons), tear down on AO end.

true
