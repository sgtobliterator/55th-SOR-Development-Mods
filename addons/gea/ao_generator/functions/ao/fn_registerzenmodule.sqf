// =====================================================================
// GEA_fnc_registerZenModule
//   postInit — registers the "Generate Enemy AO" custom module.
//
//   ZEN passes the callback two args:
//     _this = [_position, _object]
//   where:
//     _position : the world position the curator dropped the module
//     _object   : the object the module is attached to (or objNull
//                 if dropped on terrain)
//
//   Position strategy, in order:
//     1. _this select 0       (where ZEN says the module was placed)
//     2. getPosATL _object    (in case position came back as [0,0,0]
//                              but an object was hit)
//     3. curatorMouseOver     (last-resort terrain hover)
//     4. curatorCamera        (very last resort — used to be primary,
//                              which is the bug we're fixing)
// =====================================================================

#include "..\..\script_component.hpp"

if (!hasInterface) exitWith {};

if (isNil "zen_custom_modules_fnc_register") exitWith {
    diag_log text "[GEA] Zeus Enhanced not loaded - module NOT registered.";
};

private _onPlace = {
    diag_log text format ["[GEA] callback fired. _this = %1", _this];

    _this params [
        ["_argPos", [0,0,0], [[]], [2,3]],
        ["_argObj", objNull, [objNull]]
    ];

    private _pos = [0, 0, 0];

    // -- 1. PRIMARY: position ZEN passes to the callback ----------------
    // _argPos can be a [x,y] or [x,y,z] array. Normalize to length-3.
    if (count _argPos >= 2 && { !(_argPos isEqualTo [0,0,0]) }) then {
        if (count _argPos == 2) then {
            _pos = [_argPos select 0, _argPos select 1, 0];
        } else {
            _pos = +_argPos;
        };
    };

    // -- 2. Attached object's position -----------------------------------
    if (_pos isEqualTo [0, 0, 0] && { !isNull _argObj }) then {
        _pos = getPosATL _argObj;
    };

    // -- 3. curatorMouseOver — NULAR command, returns [type, target]. --
    if (_pos isEqualTo [0, 0, 0]) then {
        private _mo = curatorMouseOver;
        diag_log text format ["[GEA] curatorMouseOver = %1", _mo];
        if (count _mo >= 2) then {
            private _target = _mo select 1;
            if (_target isEqualType [] && { count _target >= 2 }) then {
                _pos = _target;
            };
            if (_target isEqualType objNull && { !isNull _target }) then {
                _pos = getPosATL _target;
            };
        };
    };

    // -- 4. Curator camera (last resort) ---------------------------------
    if (_pos isEqualTo [0, 0, 0]) then {
        private _cam = curatorCamera;
        if (!isNull _cam) then {
            _pos = getPosATL _cam;
            _pos set [2, 0];
        };
    };

    diag_log text format ["[GEA] chosen pos = %1", _pos];

    [_pos] call GEA_fnc_openDialog;
};

[
    "GEA",
    "Generate Enemy AO",
    _onPlace,
    "\a3\ui_f\data\igui\cfg\simpletasks\types\attack_ca.paa"
] call zen_custom_modules_fnc_register;

diag_log text "[GEA] Generate Enemy AO module registered.";
