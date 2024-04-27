#pragma once
#ifndef TextButtonLAF_h
#define TextButtonLAF_h

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include "Colors.h"
#include "Gradient.h"

namespace viator_core
{
    class CustomTextButton : public juce::LookAndFeel_V4
    {
        public:
        CustomTextButton();
        
        void drawButtonBackground (juce::Graphics& g,
                                   juce::Button& button,
                                   const juce::Colour& backgroundColour,
                                   bool shouldDrawButtonAsHighlighted,
                                   bool shouldDrawButtonAsDown) override;
        
        juce::Font getTextButtonFont (juce::TextButton&, int buttonHeight) override;
        
        void drawButtonText (juce::Graphics& g, juce::TextButton& button,
                             bool boolshouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
        
        enum class ButtonColorMode
        {
            kNormal,
            kRainbow
        };
        
        void setViatorButtonColorMode(ButtonColorMode btnColorMode){_btnColorMode = btnColorMode;};
        
    private:
        ButtonColorMode _btnColorMode = ButtonColorMode::kNormal;
    };
}

#endif
