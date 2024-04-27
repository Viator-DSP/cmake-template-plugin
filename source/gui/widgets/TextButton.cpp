#include "TextButton.h"

namespace viator_core
{

TextButton::TextButton()
{
    initButtonColors();
    _button.addMouseListener(this, false);
}

TextButton::TextButton(const juce::String& name)
{
    _button.setButtonText(name);
    _button.setName(name);
    initButtonColors();
}

TextButton::~TextButton()
{
    setLookAndFeel(nullptr);
    _button.removeMouseListener(this);
}

void TextButton::paint (juce::Graphics& g)
{
}

void TextButton::resized()
{
    _button.setBounds(getLocalBounds());
}

void TextButton::initButtonColors()
{
    _button.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::transparentBlack);
    _button.setColour(juce::ComboBox::ColourIds::outlineColourId, juce::Colour(80, 80, 80));
    _button.setLookAndFeel(&_customTextButton);
    addAndMakeVisible(_button);

    //_dropShadow = std::make_unique<juce::DropShadower>(juce::DropShadow(juce::Colours::black.withAlpha(0.25f), 5, {}));
    //_dropShadow->setOwner(this);
}

void TextButton::setViatorButtonColorMode(viator_core::CustomTextButton::ButtonColorMode btnColorMode)
{
    _customTextButton.setViatorButtonColorMode(btnColorMode);
    _button.repaint();
}

}
