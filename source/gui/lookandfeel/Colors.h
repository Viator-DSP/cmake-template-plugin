#pragma once
#ifndef Colors_h
#define Colors_h

#include <juce_gui_basics/juce_gui_basics.h>

namespace viator_core
{
class Colors
{
public:
    Colors() = default;
    
    static juce::Colour getViatorTextColor()
    {
        return _textColor;
    }
    
    static juce::Colour getViatorDownColor()
    {
        return _downColor;
    }
    
    static juce::Colour getViatorBGLightColor()
    {
        return _lightBGColor;
    }
    
    static juce::Colour getPrimaryBGColor()
    {
        return _primaryBGColor;
    }
    
    static juce::Colour getSecondaryBGColor()
    {
        return _secondaryBGColor;
    }
    
    static juce::Colour getTirtiaryBGColor()
    {
        return _tertiaryBGColor;
    }
    
    static juce::Colour getViatorBGCompColor()
    {
        return _compBGColor;
    }
    
    static juce::Colour getPrimaryAccentColor()
    {
        return _primaryAccentColor;
    }
    
    static juce::Colour getCompActiveColor()
    {
        return _compActiveColor;
    }
    
    static juce::Colour getOutlineColor()
    {
        return _outlineColor;
    }
    
    static void setRainbowGradient(juce::Graphics& g, const juce::Rectangle<int> rect, const float midPoint)
    {
        g.setGradientFill(juce::ColourGradient::horizontal(juce::Colour(22, 191, 253),
                                                           0,
                                                           juce::Colour(196, 113, 237),
                                                           rect.getWidth() * midPoint));
    }
    
private:
    static inline juce::Colour _textColor = juce::Colour(166, 172, 204);
    static inline juce::Colour _downColor = juce::Colour(206, 206, 206).withAlpha(0.1f);
    static inline juce::Colour _lightBGColor = juce::Colour(50, 58, 77);
    static inline juce::Colour _primaryBGColor = juce::Colour(30, 35, 46);
    static inline juce::Colour _secondaryBGColor = juce::Colour(42, 42, 42);
    static inline juce::Colour _tertiaryBGColor = juce::Colour(44, 44, 44);
    static inline juce::Colour _primaryAccentColor = juce::Colour(242, 97, 63);
    static inline juce::Colour _compBGColor = juce::Colour(55, 54, 55);
    static inline juce::Colour _compActiveColor = juce::Colour(196, 113, 237);
    static inline juce::Colour _outlineColor = juce::Colour(198, 208, 245).withAlpha(0.25f);
};
}

#endif
