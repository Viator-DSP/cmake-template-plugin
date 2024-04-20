#include "Menu.h"

namespace viator_core
{

Menu::Menu()
{
    setColour(juce::ComboBox::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    setColour(juce::ComboBox::ColourIds::arrowColourId, viator_core::Colors::getViatorTextColor());
    setColour(juce::ComboBox::ColourIds::backgroundColourId, viator_core::Colors::getViatorBGLightColor());
    setColour(juce::ComboBox::ColourIds::outlineColourId, viator_core::Colors::getOutlineColor());
    setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, viator_core::Colors::getCompActiveColor());
    setLookAndFeel(&_customLAF);
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::buttonColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::arrowColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, viator_core::Colors::getViatorBGCompColor());
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::backgroundColourId, viator_core::Colors::getPrimaryBGColor().brighter(0.05));
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::textColourId, viator_core::Colors::getViatorTextColor());
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::highlightedTextColourId, juce::Colours::whitesmoke);
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::highlightedBackgroundColourId, viator_core::Colors::getCompActiveColor());
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
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::highlightedTextColourId, juce::Colours::whitesmoke);
    getLookAndFeel().setColour(juce::PopupMenu::ColourIds::highlightedBackgroundColourId, viator_core::Colors::getCompActiveColor());
    repaint();
}

void Menu::enableShadow(bool enable)
{
    if (enable)
    {
        _dropShadow = std::make_unique<juce::DropShadower>(juce::DropShadow(juce::Colours::black.withAlpha(1.0f), 5, {}));
        _dropShadow->setOwner(this);
    }
    
    else
    {
        _dropShadow.reset();
        _dropShadow->setOwner(nullptr);
    }
    
    repaint();
}

void Menu::setMenuJustification(juce::Justification justification)
{
    _customLAF.setMenuJustification(justification);
    repaint();
};

}
