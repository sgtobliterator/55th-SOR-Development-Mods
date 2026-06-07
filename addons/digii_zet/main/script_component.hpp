#define COMPONENT main
#define COMPONENT_BEAUTIFIED Main
#include "\z\digii_zet\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MAIN
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MAIN
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MAIN
#endif

#include "\z\digii_zet\addons\main\script_macros.hpp"


// UI grid
#define SIZEX ((safeZoneW / safeZoneH) min 1.2)
#define SIZEY (SIZEX / 1.2)
#define W_PART(num) (num * (SIZEX / 40))
#define H_PART(num) (num * (SIZEY / 25))
#define X_PART(num) (W_PART(num) + (safeZoneX + (safeZoneW - SIZEX) / 2))
#define Y_PART(num) (H_PART(num) + (safeZoneY + (safeZoneH - SIZEY) / 2))
#define GUI_TEXT_SIZE_SMALL 	(GUI_GRID_H * 0.8)
#define GUI_TEXT_SIZE_MEDIUM 	(GUI_GRID_H * 1)
#define GUI_TEXT_SIZE_LARGE 	(GUI_GRID_H * 1.2)

//Top of all UIs
#define WINDOW_TOPAbs (0.5 - WINDOW_HAbs * 0.5 + CTRL_DEFAULT_H)

//Either uses full width and leave only 5 grids left and right,
//or it uses a maximum of 400 grids. This way, on ultra wide and super ultra wide,
//the UI will not become too wide
#define WINDOW_W_WIDE ((safeZoneW / GRID_W - 10) min 400)

//Width of edit attributes window
#define WINDOW_W_ATTRIBUTES 80

//Statusbar
#define SPACE_X (2 * pixelW)
#define ORIGIN_X_STATUSBAR (safeZoneW - 60 * GRID_W)

#define LB_HTML "<br/>"
#define INDENT "    "
#define SHOW_IN_ROOT value = 0
#define EDIT_W 10
#define EDIT_W_WIDE 11
#define CTRL_DEFAULT_H (ATTRIBUTE_CONTENT_H * GRID_H)
#define SIZEEX_BASE ((1 / (getResolution select 3)) * pixelGrid * 0.5)

// IDCs for the inner controls of ZET_NumberSlider controlsGroup.
// Chosen outside vanilla / common-mod IDC ranges to avoid collisions.
#define IDC_ZET_RANGE_SLIDER 4720100
#define IDC_ZET_RANGE_EDIT   4720101
