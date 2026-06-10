#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Computes the number of entities to spawn for a zone using the density
 * formula: round(density * radius / SPAWN_DENSITY_DIVISOR), clamped to
 * [1, PER_ZONE_CAP]. Linear scaling in both inputs.
 *
 * Reference values (divisor=15, cap=30):
 *   density=5,  radius=75   -> 25
 *   density=5,  radius=25   -> 8
 *   density=10, radius=200  -> 30 (capped)
 *   density=1,  radius=50   -> 3
 *
 * Arguments:
 * 0: Radius <NUMBER>
 * 1: Density <NUMBER>
 *
 * Return Value:
 * Entity count <NUMBER>
 *
 * Example:
 * [75, 5] call digii_ambient_agents_fnc_computeSpawnCount
 *
 * Public: No
 */

params ["_radius", "_density"];

private _count = round (_density * _radius / SPAWN_DENSITY_DIVISOR);
_count max 1 min PER_ZONE_CAP
