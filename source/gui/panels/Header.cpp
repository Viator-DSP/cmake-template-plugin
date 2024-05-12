#include "Header.h"
#include "../../PluginProcessor.h"

namespace viator_core
{

Header::Header(PluginProcessor& p) : audio_processor(p), nav_bar(audio_processor)
{
    addAndMakeVisible(nav_bar);
    initOversamplingMenuProps();
    initStereoMenuProps();
    initExtrasButton();
    init_shadow();
}

Header::~Header()
{
    drop_shadow.reset();
}

 void Header::paint (juce::Graphics& g)
 {
     //g.setColour(viator_core::Colors::getViatorBGLightColor().darker(0.3));
     //g.fillRoundedRectangle(getLocalBounds().toFloat(), 6.0f);
    
     g.setColour(viator_core::Colors::getViatorTextColor().withAlpha(0.1f));
     //auto width = getWidth() * 0.998;
     //auto height = getHeight() * 0.98;
     //g.drawRoundedRectangle(getLocalBounds().toFloat().withSizeKeepingCentre(width, height), 6.0f, getWidth() * 0.001f);
     g.drawLine(0, getHeight(), getWidth(), getHeight(), 2.0f);
    
     // force image to color correctly
     g.setColour(juce::Colours::white.withAlpha(0.7f));

     // add logo image
     auto logo = juce::ImageCache::getFromMemory(BinaryData::landon_png, BinaryData::landon_pngSize);
     auto logo_width = static_cast<int>(getWidth() * 0.2);
     auto logo_x = static_cast<int>(getWidth() * 0.01);
     auto logo_y = static_cast<int>(getWidth() * 0.01);
     auto logo_height = static_cast<int>(logo_width * 0.218);
     g.drawImageWithin(logo,
                       logo_x,
                       logo_y,
                       logo_width,
                       logo_height,
                       juce::RectanglePlacement::centred);
}

void Header::resized()
{
    auto compX = static_cast<int>(getWidth() * 0.285);
    auto compY = static_cast<int>(getHeight() * 0.225);
    auto compWidth = static_cast<int>(getWidth() * 0.45);
    auto compHeight = static_cast<int>(getHeight() * 0.55);
    auto padding = static_cast<int>(getWidth() * 0.007);
    nav_bar.setBounds(compX, compY, compWidth, compHeight);

    compX = nav_bar.getRight() + padding;
    compWidth = static_cast<int>(getWidth() * 0.095);
    oversample_menu.setBounds(compX, compY, compWidth, compHeight);

    compX = oversample_menu.getRight() + padding;
    stereo_mode_menu.setBounds(compX, compY, compWidth, compHeight);

    compWidth = static_cast<int>(compWidth * 0.5);
    compX = stereo_mode_menu.getRight() + padding;
    extras_button.setBounds(compX, compY, compWidth, compHeight);
}

void Header::initExtrasButton()
{
    extras_button.getButton().setButtonText("?");
    extras_button.setViatorTooltip("Opens/closes the included user manual for Duplex Comp.");
    extras_button.getButton().setColour(juce::TextButton::ColourIds::buttonOnColourId,
                                        viator_core::Colors::getViatorTextColor());
    extras_button.getButton().setColour(juce::ComboBox::ColourIds::outlineColourId,
                                        viator_core::Colors::getOutlineColor());
    extras_button.getButton().setColour(juce::TextButton::ColourIds::textColourOffId,
                                        viator_core::Colors::getViatorTextColor());
    extras_button.getButton().setColour(juce::TextButton::ColourIds::textColourOnId,
                                        viator_core::Colors::getPrimaryBGColor());
    extras_button.getButton().setClickingTogglesState(true);
    addAndMakeVisible(extras_button);

    extras_button.getButton().onClick = [this]()
    {
        sendActionMessage("extras_button_clicked");
    };
}

 void Header::initOversamplingMenuProps()
 {
     juce::StringArray choices = {"HQ Off", "HQ X2", "HQ X4", "HQ X8"};
     for (int i = 0; i < choices.size(); ++i)
     {
         oversample_menu.addItem(choices[i], i + 1);
     }
    
     oversample_menu.setMenuJustification(juce::Justification::centred);
    
     addAndMakeVisible(oversample_menu);
     oversample_attach = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
             audio_processor.get_tree_state(),
             viator_core::Parameters::hqID,
             oversample_menu);
 }

 void Header::initStereoMenuProps()
 {
     juce::StringArray choices = {"Stereo", "Mono", "Mid", "Side"};
     for (int i = 0; i < choices.size(); ++i)
     {
         stereo_mode_menu.addItem(choices[i], i + 1);
     }
    
     stereo_mode_menu.setMenuJustification(juce::Justification::centred);
    
     addAndMakeVisible(stereo_mode_menu);
     stereo_attach = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
             audio_processor.get_tree_state(),
             viator_core::Parameters::stereoID,
             stereo_mode_menu);
 }

void Header::init_shadow()
{
    auto shadow_color = juce::Colours::black.withAlpha(0.15f);
    auto shadow = juce::DropShadow(shadow_color, 5, {});
    drop_shadow = std::make_unique<juce::DropShadower>(shadow);
    drop_shadow->setOwner(this);
}

}
