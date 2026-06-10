// =====================================================================
// ao_generator_dialog.hpp
// ZEN dialog definition — populated by zen_dialog_fnc_create from
// fn_openDialog.sqf. Kept as a separate file so designers can iterate
// on the UI without touching configs/functions.
//
// NOTE: the ZEN dialog framework uses ARRAYS of "rows" rather than
//   classical RscControls. The structure below is consumed by
//   GEA_fnc_openDialog and passed straight to zen_dialog_fnc_create.
// =====================================================================

// Section labels — kept as macros so we can localize later.
#define SECTION_GENERAL  "General"
#define SECTION_ENEMY    "Enemy Composition"
#define SECTION_PATROLS  "Patrols & Garrison"
#define SECTION_VEHICLES "Vehicles & Air"
#define SECTION_ADVANCED "Advanced"
