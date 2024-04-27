#include "NavBar.h"
#include "../../PluginProcessor.h"

namespace viator_core
{

NavBar::NavBar(PluginProcessor& p) : audioProcessor(p), preset_browser(audioProcessor)
{
    initButtons();
    init_preset_browser();
}

void NavBar::resized()
{
    const auto buttonHeight = static_cast<int>(getHeight());
    const auto buttonWidth = static_cast<int>(getWidth() * 0.1);
    auto buttonX = 0;
    constexpr auto buttonY = 0;
    const auto presetWidth = static_cast<int>(getWidth() * 0.75);
    const auto padding = static_cast<int>(getWidth() * 0.025);
    
    preset_buttons[0]->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
    buttonX += buttonWidth + padding;
    preset_buttons[1]->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
    buttonX += buttonWidth + padding;
    preset_browser.setBounds(buttonX, buttonY, presetWidth, buttonHeight);
}

void NavBar::initButtons()
{
    for (int i = 0; i < num_buttons; i++)
    {
        // Create and add a new TextButton to the preset_buttons array
        using btn = viator_core::TextButton;
        preset_buttons.add(std::make_unique<btn>(preset_button_names[i]));
        auto& button = preset_buttons[i]->getButton();

        // Set button color modes
        using c_btn = viator_core::CustomTextButton::ButtonColorMode;
        preset_buttons[i]->setViatorButtonColorMode(c_btn::kNormal);

        // Configure button colours
        button.setColour(juce::ComboBox::ColourIds::outlineColourId,
                         viator_core::Colors::getOutlineColor());
        button.setColour(juce::TextButton::ColourIds::textColourOffId,
                         viator_core::Colors::getViatorTextColor());
        button.setColour(juce::TextButton::ColourIds::textColourOnId,
                         viator_core::Colors::getViatorTextColor());

        // Make the button visible within the component
        addAndMakeVisible(preset_buttons[i]);
    }

    auto tooltip =
    "Loads a preset from your computer. The preset must have been made from this plugin!";

    preset_buttons[0]->getButton().setClickingTogglesState(false);
    preset_buttons[0]->setViatorTooltip(tooltip);
    preset_buttons[0]->getButton().onClick = [this]()
    {
        preset_browser.importPreset();
    };

    preset_buttons[1]->getButton().setClickingTogglesState(false);

    preset_buttons[1]->getButton().onClick = [this]()
    {
        preset_browser.savePreset();
    };

    tooltip =
    "Saves the current state as an xml file in your documents folder (under this plugin name) "
    "and populates it in the User menu.";
    preset_buttons[1]->setViatorTooltip(tooltip);
}

void NavBar::init_preset_browser()
{
    addAndMakeVisible(preset_browser);
    using presetType = viator_core::PresetBrowser::PresetType;
    preset_browser.createPresetFolder();
    preset_browser.prepareFactoryMenu();

    preset_browser.addFactoryFiles(BinaryData::factorypreset_xml,
                                   BinaryData::factorypreset_xmlSize,
                                   "Factory Preset Test", presetType::kMix);

    preset_browser.populateMenu();
}

void NavBar::setBGColor(juce::Colour newBGColor)
{
    background_color = newBGColor;
    repaint();
}

}
