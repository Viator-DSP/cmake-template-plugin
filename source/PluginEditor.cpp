#include "PluginEditor.h"

PluginEditor::PluginEditor(PluginProcessor &p)
    : AudioProcessorEditor(&p), audio_processor(p), header_comp(audio_processor)
{
    addAndMakeVisible(header_comp);
    header_comp.addActionListener(this);

    addAndMakeVisible(extras_page);

    test_slider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    test_slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 64, 32);
    test_attach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audio_processor.get_tree_state(), "outputID", test_slider);
    addAndMakeVisible(test_slider);

    addAndMakeVisible(info_popup);

    header_comp.get_navbar().get_preset_browser().addActionListener(this);

    juce::ignoreUnused(audio_processor);
    auto mult = 1.5;
    setSize(800 * mult, 452 * mult);
    setResizable(true, true);
    getConstrainer()->setFixedAspectRatio(1.618);
    setResizeLimits(600, 300, 1440, 720);
}

PluginEditor::~PluginEditor()
{
    header_comp.get_navbar().get_preset_browser().removeActionListener(this);
}

void PluginEditor::paint(juce::Graphics &g)
{
    // background
    auto rect = getLocalBounds();
    auto bgColor = viator_core::Colors::getPrimaryBGColor();
    auto radType = viator_core::Gradient::RectShape::kRounded;
    auto contrast = 0.05f;
    viator_core::Gradient::addRadialGradient(g, bgColor, rect, radType, contrast);
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

    compWidth = static_cast<int>(getWidth() * 0.4);
    test_slider.setBounds(getLocalBounds().withSizeKeepingCentre(compWidth, compWidth));

    compWidth = static_cast<int>(getWidth() * 0.4);
    compHeight = static_cast<int>(getHeight() * 0.3);
    info_popup.setBounds(getLocalBounds().withSizeKeepingCentre(compWidth, compHeight));
    info_popup.setVisible(false);
}

void PluginEditor::actionListenerCallback(const juce::String &message)
{
    if (message == "extras_button_clicked")
    {
        resized();
    }

    else if (message == "preset_error")
    {
        info_popup.set_title_and_content("Preset Browser Error!", "It seems that the project name in the preset file, the .xml file, is different from this plugin's name, make sure you're trying to load a preset for this plugin!");
        info_popup.setVisible(true);
    }
}

void PluginEditor::mouseDown(const juce::MouseEvent &event)
{
    info_popup.setVisible(false);
}