// =====================================================================
// GEA_fnc_openDialog
//   Stage 1 of the AO setup — Side picker.
//
//   Per the project plan, the Side selector lives in its own menu:
//   BLUFOR / OPFOR / Independent / Civilian. After the curator
//   confirms a side, we open Stage 2 (fn_openConfigDialog) which
//   shows the faction list dynamically filtered for that side.
//
//   Inputs:
//     _center : PositionAGL — the curator's clicked AO center.
// =====================================================================

#include "..\..\script_component.hpp"

if (isNil "zen_dialog_fnc_create") exitWith {
    diag_log text "[GEA] Zeus Enhanced not loaded — cannot open dialog.";
};

params [["_center", [0,0,0], [[]], [3]]];

private _sides      = call GEA_fnc_getSides;            // [[side, label], ...]
private _sideValues = _sides apply { _x select 0 };     // [west, east, independent, civilian]
private _sideLabels = _sides apply { _x select 1 };

// Default selection index = OPFOR if present, else 0.
private _defaultIdx = _sideValues find east;
if (_defaultIdx < 0) then { _defaultIdx = 0 };

// --- ZEN dialog row format (validated against current ZEN):
//   [TYPE, [displayName, tooltip, section], data, defaultValue, isRequired]
// For COMBO, data = [VALUES, LABELS, PICTURES, DEFAULT_INDEX]
// and the returned value in onConfirm is the SELECTED VALUE (not index).
private _content = [
    ["COMBO",
     ["Side", "BLUFOR / OPFOR / Independent / Civilian", "Side"],
     [_sideValues, _sideLabels, [], _defaultIdx],
     _sideValues select _defaultIdx,
     true]
];

[
    "Generate Enemy AO — Pick Side",
    _content,
    {
        params ["_values", "_args"];
        _values params ["_side"];
        _args   params ["_center"];

        // Stage 2 — open the main config dialog with factions filtered
        // for the chosen side.
        [_center, _side] call GEA_fnc_openConfigDialog;
    },
    {},                  // onCancel
    [_center]
] call zen_dialog_fnc_create;
