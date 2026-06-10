#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Module_F callback for the civilian zone module. Sibling of
 * fnc_moduleZone -- same three-way display branch but opens the
 * civilian dialog. Runtime non-Zeus path (e.g. 3DEN-placed module
 * previewed into a mission) hands off to registerFromLogicCivilian
 * so the saved logic spawns its civilians at mission start.
 *
 * Arguments:
 * 0: Mode <STRING>
 * 1: Input arguments per Module_F convention <ARRAY>
 *
 * Return Value:
 * True <BOOL>
 *
 * Example:
 * Invoked by the engine via the module's `function` config entry; do not call manually.
 *
 * Public: No
 */

params [["_mode", "", [""]], ["_input", [], [[]]]];

switch _mode do {
    case "attributesChanged3DEN";
    case "init": {
        _input params [
            ["_logic", objNull, [objNull]],
            ["_isActivated", true, [true]],
            ["_isCuratorPlaced", false, [true]]
        ];

        if (isNull _logic) exitWith {
            diag_log "[digii_ambient] moduleZoneCivilian: _logic is null, skipping";
        };

        if (!local _logic) exitWith {
            diag_log format ["[digii_ambient] moduleZoneCivilian: _logic %1 not local, skipping", _logic];
        };

        if (!_isActivated) then {
            _logic setVariable ["bis_fnc_initModules_activate", true, !isServer];
        };

        // Stash the logic so the civilian dialog's controls can find it.
        GVAR(currentDialogLogic) = _logic;

        if (_isCuratorPlaced) then {
            // Zeus context — display 312 = RscDisplayCurator
            findDisplay 312 createDisplay "digii_ambient_RscDisplayZoneSettingsCivilian";
        } else {
            if (is3DEN) then {
                // Eden editor — display 313 = Display3DENMission
                findDisplay 313 createDisplay "digii_ambient_RscDisplayZoneSettingsCivilian";
            } else {
                // Mission runtime (preview / scripted placement): no dialog,
                // just register the civilian zone server-side. Mirrors
                // fnc_moduleZone's military runtime branch.
                if (!isServer) exitWith {};
                [_logic] call FUNC(registerFromLogicCivilian);
            };
        };
    };
};

true
