#pragma once
#ifndef Header_h
#define Header_h
#include <juce_gui_basics/juce_gui_basics.h>
#include "NavBar.h"
#include "../widgets/TextButton.h"
#include "../widgets/Menu.h"
#include "BinaryData.h"

class PluginProcessor;

namespace viator_core
{

class Header :
    public juce::Component,
    public juce::ActionBroadcaster,
    public juce::ChangeListener,
    public juce::Timer
{
public:
    explicit Header(PluginProcessor&);
    ~Header() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    // void setImage(const juce::Image logo){_logo = logo;};
    // bool getSettingsPagePower(){return nav_bar.getSettingsPagePower();};
    // void createPresetFolder(){nav_bar.createPresetFolder();}
    // bool getDoesPresetFolderExist(){return nav_bar.getDoesPresetFolderExist();};
    // NavBar& getNavBar(){return nav_bar;};
    // viator_core::Dial& getMacroDial(){return _macroDial;};
    viator_core::TextButton& get_extras_button() {return extras_button;}
    NavBar& get_navbar() {return nav_bar;}
    
private:
    PluginProcessor& audio_processor;

    NavBar nav_bar;
    
    //viator_core::Dial _macroDial;
    // std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> _macroAttachment;
    
     viator_core::TextButton extras_button;
    void initExtrasButton();
    
     viator_core::Menu oversample_menu;
     viator_core::Menu stereo_mode_menu;
    // std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> _oversamplingAttachment;
    // std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> _stereoAttachment;
     void initOversamplingMenuProps();
     void initStereoMenuProps();
    
     void changeListenerCallback(juce::ChangeBroadcaster* source) override;
    
    // void mouseEnter(const juce::MouseEvent &event) override;
    // void mouseExit(const juce::MouseEvent &event) override;
    
    // bool _mouseListenerAdded = false;
    // bool _initialized = false;
    
    std::unique_ptr<juce::DropShadower> drop_shadow;
    
    void timerCallback() override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
}

#endif 
