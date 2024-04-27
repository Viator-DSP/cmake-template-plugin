#include "Menu.h"

namespace viator_core
{

Menu::Menu()
{
    setColour(juce::ComboBox::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    setColour(juce::ComboBox::ColourIds::arrowColourId, viator_core::Colors::getViatorTextColor());
    setColour(juce::ComboBox::ColourIds::backgroundColourId, juce::Colours::transparentBlack);
    setColour(juce::ComboBox::ColourIds::outlineColourId, viator_core::Colors::getOutlineColor());
    setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, viator_core::Colors::getCompActiveColor());
    setLookAndFeel(&_customLAF);
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::buttonColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::arrowColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, viator_core::Colors::getViatorBGCompColor());
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::backgroundColourId, viator_core::Colors::getViatorBGLightColor().withAlpha(0.8f));
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::highlightedTextColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::highlightedBackgroundColourId, viator_core::Colors::getOutlineColor().withAlpha(0.25f));
}

Menu::~Menu()
{
    setLookAndFeel(nullptr);
}

void Menu::setTransparent()
{
    setColour(juce::ComboBox::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    setColour(juce::ComboBox::ColourIds::arrowColourId, viator_core::Colors::getViatorTextColor());
    setColour(juce::ComboBox::ColourIds::backgroundColourId, juce::Colours::transparentBlack);
    setColour(juce::ComboBox::ColourIds::outlineColourId, juce::Colours::transparentBlack);
    setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, juce::Colours::transparentBlack);
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::buttonColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::arrowColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, viator_core::Colors::getViatorBGCompColor());
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::backgroundColourId, viator_core::Colors::getPrimaryBGColor().brighter(0.05));
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::highlightedTextColourId, juce::Colours::black);
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::highlightedBackgroundColourId, viator_core::Colors::getCompActiveColor());
    repaint();
}

void Menu::enableShadow(bool enable)
{
    auto state = static_cast<float>(enable);
    auto shadow_color = juce::Colours::black.withAlpha(state);
    auto drop_shadow = juce::DropShadow(shadow_color, 5, {});

    _dropShadow = std::make_unique<juce::DropShadower>(drop_shadow);
    _dropShadow->setOwner(this);

    repaint();
}

void Menu::setMenuJustification(juce::Justification justification)
{
    _customLAF.setMenuJustification(justification);
    repaint();
};

}
