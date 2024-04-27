#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include "Colors.h"

namespace viator_core
{
    class CustomMenu : public juce::LookAndFeel_V4
    {
        public:
        CustomMenu();
        
        void drawComboBox (juce::Graphics& g, int width, int height, bool,
                                           int, int, int, int, juce::ComboBox& box) override;
        void positionComboBoxText (juce::ComboBox& box, juce::Label& label) override;
        void drawComboBoxTextWhenNothingSelected (juce::Graphics& g, juce::ComboBox& box, juce::Label& label) override;
        void drawPopupMenuItem (juce::Graphics& g, const juce::Rectangle<int>& area,
                                                const bool isSeparator, const bool isActive,
                                                const bool isHighlighted, const bool isTicked,
                                                const bool hasSubMenu, const juce::String& text,
                                                const juce::String& shortcutKeyText,
                                            const juce::Drawable* icon, const juce::Colour* const textColourToUse) override;
        void drawPopupMenuBackground (juce::Graphics& g, int width, int height) override;
        void drawLabel (juce::Graphics& g, juce::Label& label) override;
        void getIdealPopupMenuItemSize (const juce::String& text, const bool isSeparator, int standardMenuItemHeight, int& idealWidth, int& idealHeight) override;
        
        void setMenuJustification(juce::Justification justification){_justification = justification;};
    private:
        juce::Justification _justification {juce::Justification::centred};
    };
}
