// Layout convention (fractions of safezoneW / safezoneH):
//   Dialog frame: x=0.20..0.80, y=0.22..0.73 (h=0.51)
//   Uniform PAD = 0.02 on all four edges (content area: x=0.22..0.78, y top=0.28)
//   Two equal columns of w=0.26 inside content; column gap = 0.04
//     - LEFT  "General Settings": x=0.22..0.48
//     - RIGHT "Role Mix":         x=0.52..0.78
//   Row pitch within columns: 0.04
//   See plan / docstring notes for the full coordinate table.

class digii_ambient_RscDisplayZoneSettings {
    idd = 70000;
    movingEnable = 1;
    enableSimulation = 1;
    onLoad = "_this spawn digii_ambient_zones_fnc_initZoneDialog;";
    onUnload = "uiNamespace setVariable ['digii_ambient_RscDisplayZoneSettings', displayNull]";

    controlsBackground[] = { "Background", "Frame", "TitleBar" };
    controls[] = {
        "GeneralSettingsHeader",
        "RadiusLabel",         "RadiusEdit",
        "SubFactionLabel",     "SubFactionCombo",
        "DensityLabel",        "DensityEdit",
        "UseBuildingsLabel",   "UseBuildingsCheck",
        "UseRoadsLabel",       "UseRoadsCheck",
        "SkillCapLabel",       "SkillCapEdit",
        "IncludeOfficerLabel", "IncludeOfficerCheck",
        "RoleMixHeader",
        "GuardsLabel",         "GuardsSlider",
        "PatrolsLabel",        "PatrolsSlider",
        "IdlersLabel",         "IdlersSlider",
        "WanderersLabel",      "WanderersSlider",
        "TotalSeparator",
        "TotalLabel",
        "FeedbackText",
        "ApplyButton",         "CancelButton"
    };

    class Background: digii_ambient_IGUIBack {
        idc = -1;
        x = "0.20 * safezoneW + safezoneX";
        y = "0.22 * safezoneH + safezoneY";
        w = "0.60 * safezoneW";
        h = "0.51 * safezoneH";
    };
    class Frame: digii_ambient_RscFrame {
        idc = -1;
        x = "0.20 * safezoneW + safezoneX";
        y = "0.22 * safezoneH + safezoneY";
        w = "0.60 * safezoneW";
        h = "0.51 * safezoneH";
    };
    class TitleBar: digii_ambient_RscText {
        idc = 70001;
        text = CSTRING(dialog_title);
        x = "0.20 * safezoneW + safezoneX";
        y = "0.22 * safezoneH + safezoneY";
        w = "0.60 * safezoneW";
        h = "0.04 * safezoneH";
        colorBackground[] = {0.15, 0.15, 0.15, 1};
        style = 2;
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 22) * 1)";
    };

    // ===== SECTION HEADERS =====

    class GeneralSettingsHeader: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_generalSettingsHeader);
        x = "0.22 * safezoneW + safezoneX";
        y = "0.28 * safezoneH + safezoneY";
        w = "0.26 * safezoneW";
        h = "0.03 * safezoneH";
        style = 2;
        colorBackground[] = {0.1, 0.1, 0.1, 0.8};
    };

    class RoleMixHeader: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_roleMixHeader);
        x = "0.52 * safezoneW + safezoneX";
        y = "0.28 * safezoneH + safezoneY";
        w = "0.26 * safezoneW";
        h = "0.03 * safezoneH";
        style = 2;
        colorBackground[] = {0.1, 0.1, 0.1, 0.8};
    };

    // ===== LEFT COLUMN: GENERAL SETTINGS =====

    class RadiusLabel: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_radius);
        x = "0.22 * safezoneW + safezoneX";
        y = "0.32 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(dialog_radius_tooltip);
    };
    class RadiusEdit: digii_ambient_RscEdit {
        idc = 70010;
        x = "0.36 * safezoneW + safezoneX";
        y = "0.32 * safezoneH + safezoneY";
        w = "0.12 * safezoneW";
        h = "0.03 * safezoneH";
        text = "75";
    };

    class SubFactionLabel: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_subFaction);
        x = "0.22 * safezoneW + safezoneX";
        y = "0.36 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(dialog_subFaction_tooltip);
    };
    class SubFactionCombo: digii_ambient_RscCombo {
        idc = 70011;
        x = "0.36 * safezoneW + safezoneX";
        y = "0.36 * safezoneH + safezoneY";
        w = "0.12 * safezoneW";
        h = "0.03 * safezoneH";
    };

    class DensityLabel: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_density);
        x = "0.22 * safezoneW + safezoneX";
        y = "0.40 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(dialog_density_tooltip);
    };
    class DensityEdit: digii_ambient_RscEdit {
        idc = 70013;
        x = "0.36 * safezoneW + safezoneX";
        y = "0.40 * safezoneH + safezoneY";
        w = "0.12 * safezoneW";
        h = "0.03 * safezoneH";
        text = "5";
    };

    class UseBuildingsLabel: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_useBuildings);
        x = "0.22 * safezoneW + safezoneX";
        y = "0.44 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(dialog_useBuildings_tooltip);
    };
    class UseBuildingsCheck: digii_ambient_RscCheckBox {
        idc = 70014;
        x = "0.36 * safezoneW + safezoneX";
        y = "0.44 * safezoneH + safezoneY";
        w = "0.025 * safezoneW";
        h = "0.03 * safezoneH";
    };

    class UseRoadsLabel: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_useRoads);
        x = "0.22 * safezoneW + safezoneX";
        y = "0.48 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(dialog_useRoads_tooltip);
    };
    class UseRoadsCheck: digii_ambient_RscCheckBox {
        idc = 70015;
        x = "0.36 * safezoneW + safezoneX";
        y = "0.48 * safezoneH + safezoneY";
        w = "0.025 * safezoneW";
        h = "0.03 * safezoneH";
    };

    class SkillCapLabel: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_skillCap);
        x = "0.22 * safezoneW + safezoneX";
        y = "0.52 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(dialog_skillCap_tooltip);
    };
    class SkillCapEdit: digii_ambient_RscEdit {
        idc = 70016;
        x = "0.36 * safezoneW + safezoneX";
        y = "0.52 * safezoneH + safezoneY";
        w = "0.12 * safezoneW";
        h = "0.03 * safezoneH";
        text = "0.2";
    };

    class IncludeOfficerLabel: digii_ambient_RscText {
        idc = -1;
        text = CSTRING(dialog_includeOfficer);
        x = "0.22 * safezoneW + safezoneX";
        y = "0.56 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(dialog_includeOfficer_tooltip);
    };
    class IncludeOfficerCheck: digii_ambient_RscCheckBox {
        idc = 70017;
        x = "0.36 * safezoneW + safezoneX";
        y = "0.56 * safezoneH + safezoneY";
        w = "0.025 * safezoneW";
        h = "0.03 * safezoneH";
    };

    // ===== RIGHT COLUMN: ROLE MIX =====

    class GuardsLabel: digii_ambient_RscText {
        idc = 70031;
        text = "Guards: 25%"; // overwritten on dialog open by fnc_updateRoleMixDisplay
        x = "0.52 * safezoneW + safezoneX";
        y = "0.32 * safezoneH + safezoneY";
        w = "0.12 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(role_guards_tooltip);
    };
    class GuardsSlider: digii_ambient_RscSlider {
        idc = 70030;
        x = "0.65 * safezoneW + safezoneX";
        y = "0.325 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.025 * safezoneH";
        onSliderPosChanged = "_this call digii_ambient_zones_fnc_updateRoleMixDisplay;";
    };

    class PatrolsLabel: digii_ambient_RscText {
        idc = 70033;
        text = "Patrols: 25%"; // overwritten on dialog open by fnc_updateRoleMixDisplay
        x = "0.52 * safezoneW + safezoneX";
        y = "0.36 * safezoneH + safezoneY";
        w = "0.12 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(role_patrols_tooltip);
    };
    class PatrolsSlider: digii_ambient_RscSlider {
        idc = 70032;
        x = "0.65 * safezoneW + safezoneX";
        y = "0.365 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.025 * safezoneH";
        onSliderPosChanged = "_this call digii_ambient_zones_fnc_updateRoleMixDisplay;";
    };

    class IdlersLabel: digii_ambient_RscText {
        idc = 70035;
        text = "Idlers: 20%"; // overwritten on dialog open by fnc_updateRoleMixDisplay
        x = "0.52 * safezoneW + safezoneX";
        y = "0.40 * safezoneH + safezoneY";
        w = "0.12 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(role_idlers_tooltip);
    };
    class IdlersSlider: digii_ambient_RscSlider {
        idc = 70034;
        x = "0.65 * safezoneW + safezoneX";
        y = "0.405 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.025 * safezoneH";
        onSliderPosChanged = "_this call digii_ambient_zones_fnc_updateRoleMixDisplay;";
    };

    class WanderersLabel: digii_ambient_RscText {
        idc = 70037;
        text = "Wanderers: 10%"; // overwritten on dialog open by fnc_updateRoleMixDisplay
        x = "0.52 * safezoneW + safezoneX";
        y = "0.44 * safezoneH + safezoneY";
        w = "0.12 * safezoneW";
        h = "0.03 * safezoneH";
        tooltip = CSTRING(role_wanderers_tooltip);
    };
    class WanderersSlider: digii_ambient_RscSlider {
        idc = 70036;
        x = "0.65 * safezoneW + safezoneX";
        y = "0.445 * safezoneH + safezoneY";
        w = "0.13 * safezoneW";
        h = "0.025 * safezoneH";
        onSliderPosChanged = "_this call digii_ambient_zones_fnc_updateRoleMixDisplay;";
    };

    // Thin separator between per-role rows and the Total sum.
    class TotalSeparator: digii_ambient_RscText {
        idc = -1;
        text = "";
        x = "0.52 * safezoneW + safezoneX";
        y = "0.49 * safezoneH + safezoneY";
        w = "0.26 * safezoneW";
        h = "0.002 * safezoneH";
        colorBackground[] = {0.5, 0.5, 0.5, 0.5};
    };

    class TotalLabel: digii_ambient_RscText {
        idc = 70040;
        text = "Total: 100%"; // overwritten on dialog open by fnc_updateRoleMixDisplay
        x = "0.52 * safezoneW + safezoneX";
        y = "0.50 * safezoneH + safezoneY";
        w = "0.26 * safezoneW";
        h = "0.03 * safezoneH";
        style = 2;
        tooltip = CSTRING(dialog_total_tooltip);
    };

    // ===== FEEDBACK LINE =====

    class FeedbackText: digii_ambient_RscText {
        idc = 70080;
        text = "";
        x = "0.22 * safezoneW + safezoneX";
        y = "0.61 * safezoneH + safezoneY";
        w = "0.56 * safezoneW";
        h = "0.04 * safezoneH";
        colorText[] = {1, 0.35, 0.35, 1};
        style = 2;
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 22) * 1)";
    };

    // ===== BUTTONS =====

    class ApplyButton: digii_ambient_RscButton {
        idc = 70090;
        text = CSTRING(dialog_apply);
        x = "0.41 * safezoneW + safezoneX";
        y = "0.67 * safezoneH + safezoneY";
        w = "0.08 * safezoneW";
        h = "0.04 * safezoneH";
        onButtonClick = "[] call digii_ambient_zones_fnc_applyZoneDialog;";
    };
    class CancelButton: digii_ambient_RscButton {
        idc = 70091;
        text = CSTRING(dialog_cancel);
        x = "0.51 * safezoneW + safezoneX";
        y = "0.67 * safezoneH + safezoneY";
        w = "0.08 * safezoneW";
        h = "0.04 * safezoneH";
        onButtonClick = "[] call digii_ambient_zones_fnc_cancelZoneDialog;";
    };
};
