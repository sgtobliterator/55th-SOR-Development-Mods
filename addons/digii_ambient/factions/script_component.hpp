#define COMPONENT factions
#define COMPONENT_BEAUTIFIED Factions
#include "\z\digii_ambient\addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_FACTIONS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_FACTIONS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_FACTIONS
#endif

#include "\z\digii_ambient\addons\main\script_macros.hpp"

// Classname substring blacklist for ambient-population units. Any class whose
// lowercased name contains any of these substrings is excluded from the
// sub-faction units pool. Mirrors ZEI's filter minus "officer" (officers are
// tracked separately by enumerateSubFactions and consumed in step 7.7).
#define UNIT_CLASS_BLACKLIST ["_story", "_vr", "competitor", "ghillie", "miller", "survivor", "crew", "diver", "pilot", "rangemaster", "uav", "unarmed"]
