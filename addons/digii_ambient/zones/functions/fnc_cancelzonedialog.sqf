#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Cancel button handler. Two paths:
 *   - Fresh placement (subFactionId never set) -> delete the just-placed
 *     module via 3DEN's delete pipeline (visible in undo history).
 *   - Re-edit (subFactionId already set) -> keep the logic, but the module
 *     may have been dragged before this Cancel; respawn so the units sync
 *     to its current position.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * Invoked by the dialog's Cancel button (onButtonClick); do not call manually.
 *
 * Public: No
 */

private _logic = GVAR(currentDialogLogic);
private _display = findDisplay 70000;

if (!isNil "_logic" && {!isNull _logic}) then {
    private _alreadyConfigured = !isNil { _logic getVariable "digii_ambient_zone_subFactionId" };
    if (_alreadyConfigured) then {
        if (is3DEN) then {
            [_logic] call FUNC(respawnModuleZone);
        };
    } else {
        if (is3DEN) then {
            delete3DENEntities [_logic];
        } else {
            deleteVehicle _logic;
        };
    };
};

if (!isNull _display) then { _display closeDisplay 0 };
