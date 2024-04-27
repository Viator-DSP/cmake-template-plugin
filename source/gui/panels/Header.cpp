#include "Header.h"
#include "../../PluginProcessor.h"

namespace viator_core
{

Header::Header(PluginProcessor& p) : audio_processor(p), nav_bar(audio_processor)
{
     addAndMakeVisible(nav_bar);
//     nav_bar.addChangeListener(this);
    
    initOversamplingMenuProps();
    initStereoMenuProps();
    initExtrasButton();
    
     drop_shadow = std::make_unique<juce::DropShadower>(juce::DropShadow(juce::Colours::black.withAlpha(0.5f), 10, {}));
     drop_shadow->setOwner(this);
    
//     startTimerHz(10);
    
//     _initialized = true;
}

 Header::~Header()
 {
//     if (_initialized)
//     {
//         nav_bar.removeChangeListener(this);
//     }
    
//     if (_mouseListenerAdded && _initialized)
//     {
//         _manualButton.removeMouseListener(getParentComponent());
//         nav_bar.getLoadButton().removeMouseListener(getParentComponent());
//         nav_bar.getSaveButton().removeMouseListener(getParentComponent());
//     }
    
//     stopTimer();
}

 void Header::paint (juce::Graphics& g)
 {
     g.setColour(viator_core::Colors::getPrimaryBGColor().brighter(0.05));
     g.fillRoundedRectangle(getLocalBounds().toFloat(), 6.0f);
    
     g.setColour(viator_core::Colors::getViatorTextColor().withAlpha(0.1f));
     auto width = getWidth() * 0.998;
     auto height = getHeight() * 0.98;
     g.drawRoundedRectangle(getLocalBounds().toFloat().withSizeKeepingCentre(width, height), 6.0f, getWidth() * 0.001f);
    
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
     auto compX = getWidth() * 0.285;
     auto compY = getHeight() * 0.225;
     auto compWidth = getWidth() * 0.45;
     auto compHeight = getHeight() * 0.55;
     auto padding = getWidth() * 0.007;

     nav_bar.setBounds(compX, compY, compWidth, compHeight);

    compX = nav_bar.getRight() + padding;
    compWidth = getWidth() * 0.095;
     oversample_menu.setBounds(compX, compY, compWidth, compHeight);

    compX = oversample_menu.getRight() + padding;
     stereo_mode_menu.setBounds(compX, compY, compWidth, compHeight);

    compWidth *= 0.5;
    compX = stereo_mode_menu.getRight() + padding;
    extras_button.setBounds(compX, compY, compWidth, compHeight);
    
    // if (getParentComponent() == nullptr) return;
    
    // if (auto parent = dynamic_cast<ViatorProcessorEditorCore*>(getParentComponent()) && !_mouseListenerAdded)
    // {
    //     _manualButton.addMouseListener(getParentComponent(), true);
    //     nav_bar.getLoadButton().addMouseListener(getParentComponent(), true);
    //     nav_bar.getSaveButton().addMouseListener(getParentComponent(), true);
    //     _mouseListenerAdded = true;
    // }
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
    
     oversample_menu.setMenuJustification(juce::Justification::centredLeft);
    
     addAndMakeVisible(oversample_menu);
     //_oversamplingAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audio_processor.getViatorTreeState(), ViatorParameters::oversamplingID, oversample_menu);
 }

 void Header::initStereoMenuProps()
 {
     juce::StringArray choices = {"Stereo", "Mono", "Mid", "Side"};
     for (int i = 0; i < choices.size(); ++i)
     {
         stereo_mode_menu.addItem(choices[i], i + 1);
     }
    
     stereo_mode_menu.setMenuJustification(juce::Justification::centredLeft);
    
     addAndMakeVisible(stereo_mode_menu);
     //_stereoAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audio_processor.getViatorTreeState(), ViatorParameters::stereoModeID, stereo_mode_menu);
     //stereo_mode_menu.setVisible(false);
 }

void Header::changeListenerCallback(juce::ChangeBroadcaster *source)
{
    // if (source == &nav_bar)
    // {
    //     sendActionMessage("header");
    // }
}

// void Header::mouseEnter(const juce::MouseEvent &event)
// {
//     if (getParentComponent() == nullptr) return;
    
//     if (auto slider = dynamic_cast<viator_core::Dial*>(event.eventComponent))
//     {
//         // if (auto parent = dynamic_cast<ViatorProcessorEditorCore*>(getParentComponent()))
//         // {
//         //     parent->getToolTipLabel().setText(slider->getViatorTooltip(), juce::dontSendNotification);
//         // }
//     }
// }

// void Header::mouseExit(const juce::MouseEvent &event)
// {
//     if (getParentComponent() == nullptr) return;
    
//     // if (auto parent = dynamic_cast<ViatorProcessorEditorCore*>(getParentComponent()))
//     // {
//     //     parent->getToolTipLabel().setText("", juce::dontSendNotification);
//     // }
// }

void Header::timerCallback()
{
    //stereo_mode_menu.setVisible(audio_processor.getIsPluginStereo());
}

}
