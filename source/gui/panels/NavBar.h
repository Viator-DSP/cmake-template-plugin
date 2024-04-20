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
    NavBar(PluginProcessor&);
    ~NavBar() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
    bool isSettingsActive();
    void setBGColor(juce::Colour newBGColor);
    
    bool getSettingsPagePower(){return _buttons[2]->getButton().getToggleState();};
    //void createPresetFolder(){audioProcessor.getPresetBrowser().createPresetFolder();};
    //bool getDoesPresetFolderExist(){return audioProcessor.getPresetBrowser().getDoesPresetFolderExist();};
    
    viator_core::TextButton& getLoadButton(){return *_buttons[getButtonIndex("Load")];};
    viator_core::TextButton& getSaveButton(){return *_buttons[getButtonIndex("Save")];};
    
private:
    PluginProcessor& audioProcessor;
    
    // buttons
    juce::OwnedArray<viator_core::TextButton> _buttons;
    juce::StringArray _buttonNameTexts =
    {
        "Load", "Save", "Settings"
    };
    
    // buttons
    void setButtonProps();
    void initButtons();
    int getButtonIndex(const juce::String& name);
    
private:
    std::unique_ptr<juce::FileChooser> _myChooser;
    
    const float _shadowAlpha = 0.25f;
    juce::Colour _bgColor = juce::Colour::fromRGB(60, 60, 73).brighter(0.1);
    const int _numButtons = 3;
    
    bool _initialized = false;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NavBar)
};

}
#endif
