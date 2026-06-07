class Title;
class Controls;
class ZET_NumberSlider: Title
{
    attributeLoad = QUOTE(ARR_2([_this,_value]) call FUNC(slider_onAttributeLoad));
    attributeSave = QUOTE(_this call FUNC(slider_onAttributeSave));
    class Controls: Controls
    {
        class Title: Title {};
        class Value: ctrlXSliderH
        {
            idc = IDC_ZET_RANGE_SLIDER;
            x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
            w = QUOTE((ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
            sliderPosition = 10000;
            sliderRange[] = {100, 10000};
            sliderStep = 100;
            lineSize = 100;
        };
        class Edit: ctrlEdit
        {
            idc = IDC_ZET_RANGE_EDIT;
            x = QUOTE((ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W);
            w = QUOTE(EDIT_W * GRID_W);
            h = QUOTE(CTRL_DEFAULT_H);
        };
    };
};
