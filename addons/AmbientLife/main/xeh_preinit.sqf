#include "script_component.hpp"

/*
 * Author: DiGii
 * CBA XEH preInit entry point for the main component. Compiles all
 * functions listed in XEH_PREP.hpp; auto-fired by the CBA XEH framework
 * before mission start.
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

ADDON = true;
