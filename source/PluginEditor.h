#pragma once

#include "PluginProcessor.h"
#include "gui/panels/Header.h"
#include "gui/panels/ExtrasPage.h"
#include "gui/lookandfeel/Gradient.h"
#include "BinaryData.h"

//==============================================================================
class PluginEditor :
        public juce::AudioProcessorEditor,
        public juce::ActionListener
{
public:
    explicit PluginEditor (PluginProcessor&);
    ~PluginEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginProcessor& audio_processor;

    viator_core::Header header_comp;
    void actionListenerCallback(const juce::String &message) override;

    viator_core::ExtrasPage extras_page;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};