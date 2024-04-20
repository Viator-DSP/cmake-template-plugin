#pragma once
#ifndef Header_h
#define Header_h
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include "BinaryData.h"
#include "../lookandfeel/Colors.h"
//#include "../components/NavBar.h"
//#include "../widgets/Dial.h"

class PluginProcessor;

namespace viator_core
{

class Header : public juce::Component, public juce::ActionBroadcaster, public juce::ChangeListener, public juce::Timer
{
public:
    Header(PluginProcessor&);
    ~Header() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    // void setImage(const juce::Image logo){_logo = logo;};
    // bool getSettingsPagePower(){return _navbar.getSettingsPagePower();};
    // void createPresetFolder(){_navbar.createPresetFolder();}
    // bool getDoesPresetFolderExist(){return _navbar.getDoesPresetFolderExist();};
    // NavBar& getNavBar(){return _navbar;};
    // viator_core::Dial& getMacroDial(){return _macroDial;};
    // viator_core::TextButton& getManualButton(){return _manualButton;};
    
private:
    PluginProcessor& audioProcessor;
    juce::Image _logo;
    
    //NavBar _navbar;
    
    //viator_core::Dial _macroDial;
    // std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> _macroAttachment;
    
    // viator_core::TextButton _manualButton;
    
    // viator_core::Menu _hqMenu;
    // viator_core::Menu _stereoMenu;
    // std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> _oversamplingAttachment;
    // std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> _stereoAttachment;
    // void setOversamplingMenuProps();
    // void setStereoMenuProps();
    
     void changeListenerCallback(juce::ChangeBroadcaster* source) override;
    
    // void mouseEnter(const juce::MouseEvent &event) override;
    // void mouseExit(const juce::MouseEvent &event) override;
    
    // bool _mouseListenerAdded = false;
    // bool _initialized = false;
    
    std::unique_ptr<juce::DropShadower> _dropShadow;
    
    void timerCallback() override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
}

#endif 
