#pragma once

#include "Global/Parameters.h"
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>
#include "dsp/filter.h"

class PluginProcessor : public juce::AudioProcessor, public juce::AudioProcessorValueTreeState::Listener

{
public:
    PluginProcessor();
    ~PluginProcessor() override;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported(const BusesLayout &layouts) const override;

    void processBlock(juce::AudioBuffer<float> &, juce::MidiBuffer &) override;

    juce::AudioProcessorEditor *createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String &newName) override;

    void getStateInformation(juce::MemoryBlock &destData) override;
    void setStateInformation(const void *data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState &get_tree_state() { return _treeState; }
    juce::ValueTree &getVariableTree() { return variableTree; }
    viator_core::ParameterData::Params &getParameterMap() { return _parameterMap; }

private:
    // tree state and parameter stuff
    viator_core::ParameterData::Params _parameterMap;
    juce::AudioProcessorValueTreeState _treeState;
    juce::ValueTree variableTree{"Variables", {}, {{"Group", {{"name", "Vars"}}, {{"Parameter", {{"id", "width"}, {"value", 0.0}}}, {"Parameter", {{"id", "height"}, {"value", 0.0}}}, {"Parameter", {{"id", "presetFolder"}, {"value", ""}}}}}}};

    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    void parameterChanged(const juce::String &parameterID, float newValue) override;
    using Parameter = juce::AudioProcessorValueTreeState::Parameter;
    static juce::String valueToTextFunction(float x) { return juce::String(static_cast<int>(x)); }
    static float textToValueFunction(const juce::String &str) { return str.getFloatValue(); }
    void updateParameters();

    juce::dsp::ProcessSpec process_spec;
    viator::SVFilter<float> test_filter;
    std::vector<float*> data;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
