// =====================================================================
// script_component.hpp — shared macros for the GEA addon.
// CBA-style component header. Keep light; this is consumed by config.cpp
// and every .sqf via `#include "script_component.hpp"`.
// =====================================================================

#define COMPONENT ao_generator
#define COMPONENT_BEAUTIFIED AO Generator
#define PREFIX gea

#ifdef DEBUG_ENABLED_AO_GENERATOR
    #define DEBUG_MODE_FULL
#endif

#define DFUNC(var) TRIPLES(ADDON,fnc,var)
#define QFUNC(var) QUOTE(DFUNC(var))

// NOTE: an earlier `LOG(MSG)` macro was removed because Arma's
// preprocessor splits macro args on top-level commas — which means
// `LOG(format ["x %1", _a])` was being parsed as LOG with TWO args
// and silently producing broken SQF. Use plain `diag_log text ...`
// or `diag_log text format [...]` directly in scripts instead.
