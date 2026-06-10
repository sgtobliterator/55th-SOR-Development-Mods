#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Civilian dialog Cancel handler. Sibling of fnc_cancelZoneDialog.
 * Two paths:
 *   - Fresh placement (subFactionId never set) -> delete the
 *     just-placed module via 3DEN's delete pipeline (visible in undo
 *     history) or runtime deleteVehicle.
 *   - Re-edit (subFactionId already set) -> keep the logic. Step 12
 *     has no respawn path; Step 13 will add one if needed.
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
private _display = findDisplay 70100;

if (!isNil "_logic" && {!isNull _logic}) then {
    private _alreadyConfigured = !isNil { _logic getVariable "digii_ambient_civZone_subFactionId" };
    if (!_alreadyConfigured) then {
        if (is3DEN) then {
            delete3DENEntities [_logic];
        } else {
            deleteVehicle _logic;
        };
    };
};

if (!isNull _display) then { _display closeDisplay 0 };
