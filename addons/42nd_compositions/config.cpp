class CfgPatches {
    class SOC42nd_compositions {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"A3_Modules_F", "A3_Modules_F_Curator"};
    };
};

class CfgEditorCategories {
    class EdCat_42ndSOC {
        displayName = "42nd SOC";
    };
};

class CfgEditorSubcategories {
    class EdSubcat_42ndSOC_Crates {
        displayName = "Crates";
    };
};

class Cfg3DEN {
    class Compositions {
        class SOC42nd_general_crate {
            path = "x\55th_dev\addons\42nd_compositions\compositions\general_crate";
            side = 8;                              // Empty/Props
            editorCategory = "EdCat_42ndSOC";
            editorSubcategory = "EdSubcat_42ndSOC_Crates";
            displayName = "General Crate";
            icon = "\x\55th_dev\addons\55th_arsenals\55th_SOR_Icon_1.paa";
        };
        class SOC42nd_med_crate {
            path = "x\55th_dev\addons\42nd_compositions\compositions\med_crate";
            side = 8;
            editorCategory = "EdCat_42ndSOC";
            editorSubcategory = "EdSubcat_42ndSOC_Crates";
            displayName = "Med Crate";
            icon = "\x\55th_dev\addons\55th_arsenals\55th_SOR_Icon_1.paa";
        };
    };
};