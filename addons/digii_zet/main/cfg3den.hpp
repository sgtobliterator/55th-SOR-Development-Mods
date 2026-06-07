class Cfg3DEN {
    class Attributes {
        #include "controls\numberSlider.hpp"
    };
    class Object {
        class AttributeCategories {
            class ADDON {
                displayName = "Zeus Enhanced Targeting";
                collapsed = 1;
                class Attributes {
                    class GVAR(targetFilter) {
                        displayName = CSTRING(SetFilterTitle);
                        tooltip = CSTRING(SetFilterTooltip);
                        property = QGVAR(targetFilter);
                        control = "Combo";
                        expression = "_this setVariable ['digii_zet_main_FilterValue', _value]; if (!is3DEN) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
                        typeName = "NUMBER";
                        defaultValue = "0";
                        condition = "objectBrain + objectVehicle";
                        class values {
                            class ALL      { name = CSTRING(Filter_All);      value = 0; default = 1; };
                            class AIR      { name = CSTRING(Filter_Air);      value = 1; };
                            class GROUND   { name = CSTRING(Filter_Ground);   value = 2; };
                            class ARMOR    { name = CSTRING(Filter_Armor);    value = 3; };
                            class INFANTRY { name = CSTRING(Filter_Infantry); value = 4; };
                            class CUSTOM   { name = CSTRING(Filter_Custom);   value = 5; };
                        };
                    };

                    class GVAR(customAir) {
                        displayName = CSTRING(CustomAir);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(customAir);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_CustomAir', _value]";
                        defaultValue = "1";
                        condition = "objectBrain + objectVehicle";
                    };
                    class GVAR(customArmor) {
                        displayName = CSTRING(CustomArmor);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(customArmor);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_CustomArmor', _value]";
                        defaultValue = "1";
                        condition = "objectBrain + objectVehicle";
                    };
                    class GVAR(customVehicles) {
                        displayName = CSTRING(CustomVehicles);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(customVehicles);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_CustomVehicles', _value]";
                        defaultValue = "1";
                        condition = "objectBrain + objectVehicle";
                    };
                    class GVAR(customInfantry) {
                        displayName = CSTRING(CustomInfantry);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(customInfantry);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_CustomInfantry', _value]";
                        defaultValue = "1";
                        condition = "objectBrain + objectVehicle";
                    };
                    class GVAR(customNaval) {
                        displayName = CSTRING(CustomNaval);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(customNaval);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_CustomNaval', _value]";
                        defaultValue = "1";
                        condition = "objectBrain + objectVehicle";
                    };
                    class GVAR(overrideMaxEngageRange) {
                        displayName = CSTRING(OverrideRangeCheckbox);
                        tooltip = CSTRING(OverrideRangeCheckboxTooltip);
                        property = QGVAR(overrideMaxEngageRange);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_OverrideMaxEngageRange', _value]; if (!is3DEN) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
                        defaultValue = "0";
                        condition = "objectBrain + objectVehicle";
                    };
                    class GVAR(maxEngageRange) {
                        displayName = CSTRING(MaxEngageRangeTitle);
                        tooltip = CSTRING(MaxEngageRangeTooltip);
                        property = QGVAR(maxEngageRange);
                        control = "ZET_NumberSlider";
                        expression = "_this setVariable ['digii_zet_main_MaxEngageRange', _value]; if (!is3DEN) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
                        typeName = "NUMBER";
                        defaultValue = "10000";
                        condition = "objectBrain + objectVehicle";
                    };
                };
            };
        };
    };
    class Group {
        class AttributeCategories {
            class ADDON {
                displayName = "Zeus Enhanced Targeting";
                collapsed = 1;
                class Attributes {
                    class GVAR(groupTargetFilter) {
                        displayName = CSTRING(SetFilterTitle);
                        tooltip = CSTRING(SetFilterTooltip);
                        property = QGVAR(groupTargetFilter);
                        control = "Combo";
                        expression = "_this setVariable ['digii_zet_main_grpFilterValue', _value]; if (!is3DEN && {count units _this > 0}) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
                        typeName = "NUMBER";
                        defaultValue = "0";
                        class values {
                            class ALL      { name = CSTRING(Filter_All);      value = 0; default = 1; };
                            class AIR      { name = CSTRING(Filter_Air);      value = 1; };
                            class GROUND   { name = CSTRING(Filter_Ground);   value = 2; };
                            class ARMOR    { name = CSTRING(Filter_Armor);    value = 3; };
                            class INFANTRY { name = CSTRING(Filter_Infantry); value = 4; };
                            class CUSTOM   { name = CSTRING(Filter_Custom);   value = 5; };
                        };
                    };

                    class GVAR(grpCustomAir) {
                        displayName = CSTRING(CustomAir);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(grpCustomAir);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_grpCustomAir', _value]";
                        defaultValue = "1";
                    };
                    class GVAR(grpCustomArmor) {
                        displayName = CSTRING(CustomArmor);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(grpCustomArmor);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_grpCustomArmor', _value]";
                        defaultValue = "1";
                    };
                    class GVAR(grpCustomVehicles) {
                        displayName = CSTRING(CustomVehicles);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(grpCustomVehicles);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_grpCustomVehicles', _value]";
                        defaultValue = "1";
                    };
                    class GVAR(grpCustomInfantry) {
                        displayName = CSTRING(CustomInfantry);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(grpCustomInfantry);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_grpCustomInfantry', _value]";
                        defaultValue = "1";
                    };
                    class GVAR(grpCustomNaval) {
                        displayName = CSTRING(CustomNaval);
                        tooltip = CSTRING(CustomFilterTooltip);
                        property = QGVAR(grpCustomNaval);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_grpCustomNaval', _value]";
                        defaultValue = "1";
                    };
                    class GVAR(grpOverrideMaxEngageRange) {
                        displayName = CSTRING(OverrideRangeCheckbox);
                        tooltip = CSTRING(OverrideRangeCheckboxTooltip);
                        property = QGVAR(grpOverrideMaxEngageRange);
                        control = "CheckboxNumber";
                        expression = "_this setVariable ['digii_zet_main_grpOverrideMaxEngageRange', _value]; if (!is3DEN && {count units _this > 0}) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
                        defaultValue = "0";
                    };
                    class GVAR(grpMaxEngageRange) {
                        displayName = CSTRING(MaxEngageRangeTitle);
                        tooltip = CSTRING(MaxEngageRangeTooltip);
                        property = QGVAR(grpMaxEngageRange);
                        control = "ZET_NumberSlider";
                        expression = "_this setVariable ['digii_zet_main_grpMaxEngageRange', _value]; if (!is3DEN && {count units _this > 0}) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
                        typeName = "NUMBER";
                        defaultValue = "10000";
                    };
                };
            };
        };
    };
};
