#pragma once
#ifndef TextButton_h
#define TextButton_h
#include "../lookandfeel/TextButtonLAF.h"
#include "../lookandfeel/Colors.h"

namespace viator_core
{
    class TextButton  : public juce::Component
    {
    public:
        TextButton();
        TextButton(const juce::String& name);
        ~TextButton() override;

        void paint (juce::Graphics&) override;
        void resized() override;
        
        void setViatorButtonColorMode(viator_core::CustomTextButton::ButtonColorMode btnColorMode);
        void setViatorTooltip(const juce::String newTooltip) {_tooltip = newTooltip;};
        juce::String getViatorTooltip(){return _tooltip;};
        juce::TextButton& getButton(){return _button;};
        
    private:
        viator_core::CustomTextButton _customTextButton;
        void initButtonColors();
        juce::String _tooltip {""};
        std::unique_ptr<juce::DropShadower> _dropShadow;
        juce::TextButton _button;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TextButton)
    };
}

#endif
