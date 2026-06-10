#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Per-frame body for the Draw3D mission EH. Despite the name, no longer
 * draws anything visible -- the zone-ring overlay was removed. The
 * remaining responsibility is the 3DEN orphan-cleanup poll: walks
 * `tracked3DENModules`, and for any module logic that has been deleted
 * (right-click → Delete, undo, etc.) despawns its tracked entities and
 * drops the entry. Runtime / Zeus contexts are a no-op.
 *
 * 3DEN has no reliable OnDeletingEntities event for placed Module_F
 * logics, hence the per-frame sweep.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * Invoked from the Draw3D mission event handler; do not call manually.
 *
 * Public: No
 */

if (!is3DEN) exitWith {};

private _tracked = missionNamespace getVariable [QGVAR(tracked3DENModules), createHashMap];
private _toRemove = [];
{
    _y params ["_trackedLogic", "_trackedEntities"];
    if (isNull _trackedLogic) then {
        {
            if (!isNull _x) then { delete3DENEntities [_x] };
        } forEach _trackedEntities;
        _toRemove pushBack _x;
    };
} forEach _tracked;
{
    _tracked deleteAt _x;
} forEach _toRemove;
