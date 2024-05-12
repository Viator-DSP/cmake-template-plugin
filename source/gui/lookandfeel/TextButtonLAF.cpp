#include "TextButtonLAF.h"

namespace viator_core
{

CustomTextButton::CustomTextButton()
{
}

void CustomTextButton::drawButtonBackground (juce::Graphics& g,
                                             juce::Button& button,
                                           const juce::Colour& backgroundColour,
                                           bool shouldDrawButtonAsHighlighted,
                                           bool shouldDrawButtonAsDown)
{
    auto cornerSize = 12.0f;
    auto bounds = button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);

    auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                                      .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);

    if (shouldDrawButtonAsDown || shouldDrawButtonAsHighlighted)
        baseColour = baseColour.contrasting (shouldDrawButtonAsDown ? 0.2f : 0.05f);

    g.setColour (baseColour);
    g.fillRoundedRectangle(bounds, cornerSize);
    
    g.setColour (button.findColour (juce::ComboBox::outlineColourId));
    
    if (!button.getToggleState())
    {
        g.drawRoundedRectangle (bounds, cornerSize, 1.0f);
    }
}

juce::Font CustomTextButton::getTextButtonFont (juce::TextButton& button, int buttonHeight)
{
    bool need_larger_text = button.getButtonText() == "?" || button.getButtonText() == "<" || button.getButtonText() == ">";
    float font_size = need_larger_text ? static_cast<float>(buttonHeight) * 0.6f : static_cast<float>(buttonHeight) * 0.4f;
    using font_style = juce::Font::FontStyleFlags;
    return juce::Font {"Trebuchet MS", font_size, font_style::plain};
}

void CustomTextButton::drawButtonText (juce::Graphics& g, juce::TextButton& button,
                                     bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    juce::Font font (getTextButtonFont (button, button.getHeight()));
    g.setFont (font);
    
    g.setColour (button.findColour (button.getToggleState() ? juce::TextButton::textColourOnId
                                    : juce::TextButton::textColourOffId)
                 .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f));
    
    if (_btnColorMode == ButtonColorMode::kRainbow)
    {
        viator_core::Colors::setRainbowGradient(g, button.getLocalBounds(), 0.7);
    }

    const int yIndent = juce::jmin (4, button.proportionOfHeight (0.3f));
    const int cornerSize = juce::jmin (button.getHeight(), button.getWidth()) / 2;

    const int fontHeight = juce::roundToInt (font.getHeight() * 0.6f);
    const int leftIndent  = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft() ? 4 : 2));
    const int rightIndent = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
    const int textWidth = button.getWidth() - leftIndent - rightIndent;

    if (textWidth > 0)
        g.drawFittedText (button.getButtonText(),
                          leftIndent, yIndent, textWidth, button.getHeight() - yIndent * 2,
                          juce::Justification::centred, 2);
}

} // namespace
