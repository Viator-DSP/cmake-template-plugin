#pragma once
#ifndef NavBar_h
#define NavBar_h
#include "../components/PresetBrowser.h"
#include "../widgets/TextButton.h"
#include "gui/components/PresetBrowser.h"
#include "BinaryData.h"

class PluginProcessor;
namespace viator_core
{

class NavBar  : public juce::Component, public juce::ChangeBroadcaster
{
public:
    explicit NavBar(PluginProcessor&);
    ~NavBar() override = default;
    
    void resized() override;
    
    void setBGColor(juce::Colour newBGColor);

    viator_core::PresetBrowser& get_preset_browser() {return preset_browser;}
    
private:
    PluginProcessor& audioProcessor;
    
    // buttons
    juce::OwnedArray<viator_core::TextButton> preset_buttons;
    void initButtons();
    juce::StringArray preset_button_names =
    {
        "Load", "Save", "Settings"
    };

    // file chooser
    std::unique_ptr<juce::FileChooser> file_chooser;

    // misc variables
    const float shadow_alpha = 0.25f;
    juce::Colour background_color = juce::Colour::fromRGB(60, 60, 73).brighter(0.1);
    const int num_buttons = 3;

    viator_core::PresetBrowser preset_browser;
    void init_preset_browser();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NavBar)
};

}
#endif
