#include "NavBar.h"

#include "../../PluginProcessor.h"

namespace viator_core
{

NavBar::NavBar(PluginProcessor& p) : audioProcessor(p)
{
    // buttons
    initButtons();
    setButtonProps();
    
    _buttons[getButtonIndex("Load")]->getButton().onClick = [this]()
    {
        audioProcessor.get_preset_browser().importPreset();
    };
    
    _buttons[getButtonIndex("Load")]->setViatorTooltip("Loads a preset from your computer. The preset must have been made from this plugin!");
    
    _buttons[getButtonIndex("Save")]->getButton().onClick = [this]()
    {
        audioProcessor.get_preset_browser().savePreset();
    };
    
    _buttons[getButtonIndex("Save")]->setViatorTooltip("Saves the current state as an xml file in your documents folder (under this plugin name) and populates it in the User menu.");
    
    _buttons[getButtonIndex("Settings")]->getButton().onClick = [this]()
    {
        sendSynchronousChangeMessage();
    };
    
    // preset browser
    addAndMakeVisible(audioProcessor.get_preset_browser());
    //audioProcessor.getPresetBrowser().addMouseListener(this, true);
    
    _initialized = true;
}

NavBar::~NavBar()
{
    if (_initialized)
    {
        //audioProcessor.getPresetBrowser().removeMouseListener(this);
    }
}

void NavBar::paint (juce::Graphics& g)
{
}

void NavBar::resized()
{
    auto buttonHeight = getHeight();
    auto buttonWidth = getWidth() * 0.1;
    auto buttonX = 0;
    auto buttonY = 0;
    auto presetWidth = getWidth() * 0.75;
    auto padding = getWidth() * 0.025;
    
    _buttons[getButtonIndex("Load")]->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
    buttonX += buttonWidth + padding;
    _buttons[getButtonIndex("Save")]->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
    buttonX += buttonWidth + padding;
    audioProcessor.get_preset_browser().setBounds(buttonX, buttonY, presetWidth, buttonHeight);
}

#pragma mark Buttons
void NavBar::setButtonProps()
{
    _buttons[getButtonIndex("Settings")]->getButton().setClickingTogglesState(true);
    _buttons[getButtonIndex("Settings")]->getButton().setColour(juce::TextButton::ColourIds::buttonOnColourId, viator_core::Colors::getCompActiveColor());
    _buttons[getButtonIndex("Save")]->getButton().setClickingTogglesState(false);
    _buttons[getButtonIndex("Load")]->getButton().setClickingTogglesState(false);
}

void NavBar::initButtons()
{
    for (int i = 0; i < _numButtons; i++)
    {
        _buttons.add(std::make_unique<viator_core::TextButton>(_buttonNameTexts[i]));
        _buttons[i]->setViatorButtonColorMode(viator_core::CustomTextButton::ButtonColorMode::kNormal);
        _buttons[i]->getButton().setColour(juce::TextButton::ColourIds::buttonColourId, viator_core::Colors::getViatorBGLightColor());
        _buttons[i]->getButton().setColour(juce::ComboBox::ColourIds::outlineColourId, viator_core::Colors::getOutlineColor());
        _buttons[i]->getButton().setColour(juce::TextButton::ColourIds::textColourOffId, viator_core::Colors::getViatorTextColor());
        _buttons[i]->getButton().setColour(juce::TextButton::ColourIds::textColourOnId, viator_core::Colors::getViatorTextColor());
        addAndMakeVisible(_buttons[i]);
    }
}

int NavBar::getButtonIndex(const juce::String &name)
{
    int index = -1;
    
    for (int i = 0; i < _numButtons; i++)
    {
        if (_buttons[i]->getButton().getName() == name)
        {
            index = i;
        }
    }
    
    jassert(index > -1);
    return index;
}

bool NavBar::isSettingsActive()
{
    return _buttons[0]->getButton().getToggleState();
}

void NavBar::setBGColor(juce::Colour newBGColor)
{
    _bgColor = newBGColor;
    repaint();
}

}
