#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Module_F callback. Modern [_mode, _input] signature; mirrors ZEI's
 * fn_mod_garrisonBuilding.sqf almost verbatim (case fall-through, !local
 * guard, three-way display branch).
 *
 * Same module class works in 3DEN AND Zeus thanks to scopeCurator = 2
 * and the _isCuratorPlaced branch.
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
            diag_log "[digii_ambient] moduleZone: _logic is null, skipping";
        };

        // MP correctness — only run on the machine that owns the entity
        if (!local _logic) exitWith {
            diag_log format ["[digii_ambient] moduleZone: _logic %1 not local, skipping", _logic];
        };

        if (!_isActivated) then {
            _logic setVariable ["bis_fnc_initModules_activate", true, !isServer];
        };

        // NOTE: no alreadyConfigured guard — attributesChanged3DEN fires on
        // entity drag, and that's the only path the user has to re-edit a
        // placed zone. Despawn-before-spawn in fnc_respawnModuleZone handles
        // cleanup on the subsequent Apply.

        // Stash the logic so the dialog's controls can find it
        GVAR(currentDialogLogic) = _logic;

        // Three-way display branch (ZEI's pattern)
        if (_isCuratorPlaced) then {
            // Zeus context — display 312 = RscDisplayCurator
            findDisplay 312 createDisplay "digii_ambient_RscDisplayZoneSettings";
        } else {
            if (is3DEN) then {
                // Eden editor — display 313 = Display3DENMission
                findDisplay 313 createDisplay "digii_ambient_RscDisplayZoneSettings";
            } else {
                // Mission runtime (preview / scripted placement): no dialog,
                // just register the zone with the server-side registry.
                if (!isServer) exitWith {};
                [_logic] call FUNC(registerFromLogic);
            };
        };
    };
};

true
