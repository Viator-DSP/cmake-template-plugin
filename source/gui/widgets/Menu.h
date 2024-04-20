#pragma once
#include "../lookandfeel/MenuLAF.h"

namespace viator_core
{
    class Menu  : public juce::ComboBox
    {
    public:
        Menu();
        
        ~Menu();
        
        void setTransparent();
        
        void enableShadow(bool enable);
        
        viator_core::CustomMenu& getLAF(){return _customLAF;};
        
        void setMenuJustification(juce::Justification justification);
        
        void setViatorTooltip(const juce::String newTooltip) {_tooltip = newTooltip;};
        juce::String getViatorTooltip(){return _tooltip;};
        
    private:
        const juce::Colour _noColor = juce::Colours::transparentBlack;
        const juce::Colour _innerBgColor = juce::Colours::black;
        
        viator_core::CustomMenu _customLAF;
        
        std::unique_ptr<juce::DropShadower> _dropShadow;
        
        juce::String _tooltip {""};
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Menu)
    };
}
