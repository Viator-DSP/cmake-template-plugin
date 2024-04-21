#pragma once
#ifndef NavBar_h
#define NavBar_h
#include "../components/PresetBrowser.h"
#include "../widgets/TextButton.h"

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
    
    //void createPresetFolder(){audio_processor.getPresetBrowser().createPresetFolder();};
    //bool getDoesPresetFolderExist(){return audio_processor.getPresetBrowser().getDoesPresetFolderExist();};

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
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NavBar)
};

}
#endif
