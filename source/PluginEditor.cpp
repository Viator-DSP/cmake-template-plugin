#include "PluginEditor.h"
#include "../libs/viatordsp-core/core/utils/window.h"

PluginEditor::PluginEditor(PluginProcessor &p)
    : AudioProcessorEditor(&p), audio_processor(p)
{
    juce::ignoreUnused(audio_processor);
    setSize(1200, 600);
}

PluginEditor::~PluginEditor()
{
}

void PluginEditor::paint(juce::Graphics &g)
{
    g.fillAll(juce::Colours::black.brighter(0.15f));
}

void PluginEditor::resized()
{
}