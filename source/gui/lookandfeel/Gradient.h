#pragma once
#ifndef Gradient_h
#define Gradient_h

#include <juce_gui_basics/juce_gui_basics.h>

namespace viator_core
{

class Gradient
{
public:
    
    enum class RectShape
    {
        kRounded,
        kSquared
    };
    
    static inline void addVerticalGradient (juce::Graphics& g,
                                            juce::Colour& gradientColor,
                                            juce::Rectangle<int>& rect,
                                            RectShape shape,
                                            float contrast)
    {
        g.setGradientFill(juce::ColourGradient::vertical(gradientColor,
                                                         rect.getY(),
                                                         gradientColor.darker(contrast),
                                                         rect.getBottom()));
        
        if (shape == RectShape::kRounded)
        {
            g.fillRoundedRectangle(rect.toFloat(), 6.0f);
        }
        
        else
        {
            g.fillRect(rect);
        }
    }
    
    static inline void addRadialGradient (juce::Graphics& g,
                                          juce::Colour& gradientColor,
                                          juce::Rectangle<int>& rect,
                                          RectShape shape,
                                          float contrast)
    {
        juce::Point<float> center = rect.getCentre().toFloat();
        juce::ColourGradient gradient(gradientColor.brighter(contrast),
                                      center.x,
                                      center.y,
                                      gradientColor.darker(contrast),
                                      rect.getRight(),
                                      rect.getBottom(),
                                      true);
        g.setGradientFill(gradient);
        
        if (shape == RectShape::kRounded)
        {
            g.fillRoundedRectangle(rect.toFloat(), 6.0f);
        }
        
        else
        {
            g.fillRect(rect);
        }
    }
    
    enum class RainbowDimension
    {
        kVertical,
        kHorizontal
    };
    
    static inline void addRainbow(juce::Graphics& g, juce::Rectangle<int>& rect, RainbowDimension dir, juce::Colour rainbowColorOne, juce::Colour rainbowColorTwo)
    {
        auto alpha = 0.5f;
        auto color1 = rainbowColorOne.withAlpha(alpha);
        auto color2 = rainbowColorTwo.withAlpha(alpha);
        auto width = rect.getWidth();
        auto height = rect.getHeight();
        auto _dir = dir == RainbowDimension::kVertical ? height : width;
        g.setGradientFill(juce::ColourGradient::vertical(color1, _dir, color2, _dir * 0.1));
    }
    
private:
};

}

#endif
