#include "script_component.hpp"

/*
 * Author: DiGii
 * CBA XEH preInit entry point for the factions component. Compiles all
 * functions listed in XEH_PREP.hpp into the digii_ambient_factions_fnc_*
 * namespace and warms the sub-faction cache by calling enumerateSubFactions.
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

[] call FUNC(enumerateSubFactions);

ADDON = true;
