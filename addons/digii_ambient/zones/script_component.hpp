#define COMPONENT zones
#define COMPONENT_BEAUTIFIED Zones
#include "\z\digii_ambient\addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_ZONES
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_ZONES
    #define DEBUG_SETTINGS DEBUG_SETTINGS_ZONES
#endif

#include "\z\digii_ambient\addons\main\script_macros.hpp"

// Maximum allowed zone radius (m). Validated in fnc_applyZoneDialog.
#define MAX_ZONE_RADIUS 300
