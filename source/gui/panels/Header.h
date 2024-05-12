#pragma once
#ifndef Header_h
#define Header_h
#include <juce_gui_basics/juce_gui_basics.h>
#include "NavBar.h"
#include "../widgets/TextButton.h"
#include "../widgets/Menu.h"
#include "../../Global/Parameters.h"
#include "BinaryData.h"

class PluginProcessor;

namespace viator_core
{

class Header :
    public juce::Component,
    public juce::ActionBroadcaster
{
public:
    explicit Header(PluginProcessor&);
    ~Header() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    viator_core::TextButton& get_extras_button() {return extras_button;}
    NavBar& get_navbar() {return nav_bar;}
    
private:
    PluginProcessor& audio_processor;

    NavBar nav_bar;
    
    viator_core::TextButton extras_button;
    void initExtrasButton();
    
     viator_core::Menu oversample_menu;
     viator_core::Menu stereo_mode_menu;
     std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oversample_attach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> stereo_attach;
     void initOversamplingMenuProps();
     void initStereoMenuProps();
    
    std::unique_ptr<juce::DropShadower> drop_shadow;
    void init_shadow();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
}

#endif 
