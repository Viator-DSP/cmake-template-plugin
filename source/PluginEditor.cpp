#include "PluginEditor.h"

PluginEditor::PluginEditor(PluginProcessor &p)
    : AudioProcessorEditor(&p), audio_processor(p), header_comp(audio_processor)
{
    addAndMakeVisible(header_comp);
    header_comp.addActionListener(this);

    addAndMakeVisible(extras_page);

    juce::ignoreUnused(audio_processor);
    setSize(1080, 540);
    setResizable(true, true);
    getConstrainer()->setFixedAspectRatio(2.0);
    setResizeLimits(600, 300, 1440, 720);
}

PluginEditor::~PluginEditor()
{
}

void PluginEditor::paint(juce::Graphics &g)
{
    // background
    auto rect = getLocalBounds();
    auto bgColor = viator_core::Colors::getPrimaryBGColor();
    auto radType = viator_core::Gradient::RectShape::kRounded;
    auto contrast = 0.025f;
    viator_core::Gradient::addRadialGradient(g, bgColor, rect, radType, contrast);

    auto bg_image = juce::ImageCache::getFromMemory(BinaryData::naturalwood_jpeg, BinaryData::naturalwood_jpegSize);
    g.drawImageWithin(bg_image,
                      0,
                      0,
                      getWidth(),
                      getHeight(),
                      juce::RectanglePlacement::stretchToFit);
}

void PluginEditor::resized()
{
    // header
    auto compX = static_cast<int>(getWidth() * 0.01);
    auto compY = static_cast<int>(getHeight() * 0.02);
    auto compWidth = static_cast<int>(getWidth() * 0.98);
    auto compHeight = static_cast<int>(getHeight() * 0.1);
    header_comp.setBounds(compX, compY, compWidth, compHeight);

    compX = static_cast<int>(getWidth() * 0.6);
    compY = static_cast<int>(getHeight() * 0.14);
    compWidth = static_cast<int>(getWidth() * 0.39);
    compHeight = static_cast<int>(getHeight() * 0.84);
    auto should_show_extras = header_comp.get_extras_button().getButton().getToggleState();
    extras_page.setBounds(compX, compY, compWidth * should_show_extras, compHeight * should_show_extras);
}

void PluginEditor::actionListenerCallback(const juce::String &message)
{
    if (message == "extras_button_clicked")
    {
        resized();
    }
}