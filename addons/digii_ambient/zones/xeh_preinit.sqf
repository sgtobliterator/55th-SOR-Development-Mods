#include "script_component.hpp"

/*
 * Author: DiGii
 * CBA XEH preInit entry point for the zones component. Compiles all
 * functions listed in XEH_PREP.hpp into the digii_ambient_zones_fnc_*
 * namespace and initializes the per-mission zone registry hashmap.
 * Auto-fired by the CBA XEH framework before mission start.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * Auto-fired by CBA XEH; do not call manually.
 *
 * Public: No
 */

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (isNil QGVAR(registry)) then {
    GVAR(registry) = createHashMap;
};

ADDON = true;
