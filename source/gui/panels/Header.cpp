#include "Header.h"
#include "../../PluginProcessor.h"

namespace viator_core
{

Header::Header(PluginProcessor& p) : audioProcessor(p), _navbar(audioProcessor)
{
     addAndMakeVisible(_navbar);
//     _navbar.addChangeListener(this);
    
     setOversamplingMenuProps();
     setStereoMenuProps();

    extras_button.getButton().setButtonText("?");
    extras_button.setViatorTooltip("Opens/closes the included user manual for Duplex Comp.");
    extras_button.getButton().setColour(juce::TextButton::ColourIds::buttonColourId,
                                        viator_core::Colors::getViatorBGLightColor());
    extras_button.getButton().setColour(juce::TextButton::ColourIds::buttonOnColourId,
                                        viator_core::Colors::getViatorBGLightColor().brighter(0.5));
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
    
     _dropShadow = std::make_unique<juce::DropShadower>(juce::DropShadow(juce::Colours::black.withAlpha(0.5f), 10, {}));
     _dropShadow->setOwner(this);
    
//     startTimerHz(10);
    
//     _initialized = true;
}

 Header::~Header()
 {
//     if (_initialized)
//     {
//         _navbar.removeChangeListener(this);
//     }
    
//     if (_mouseListenerAdded && _initialized)
//     {
//         _manualButton.removeMouseListener(getParentComponent());
//         _navbar.getLoadButton().removeMouseListener(getParentComponent());
//         _navbar.getSaveButton().removeMouseListener(getParentComponent());
//     }
    
//     stopTimer();
}

 void Header::paint (juce::Graphics& g)
 {
     g.setColour(viator_core::Colors::getPrimaryBGColor());
     g.fillRoundedRectangle(getLocalBounds().toFloat(), 6.0f);
    
     g.setColour(viator_core::Colors::getViatorBGLightColor().brighter(0.1f));
     auto width = getWidth() * 0.998;
     auto height = getHeight() * 0.98;
     g.drawRoundedRectangle(getLocalBounds().toFloat().withSizeKeepingCentre(width, height), 6.0f, getWidth() * 0.001f);
    
     // force image to color correctly
     g.setColour(juce::Colours::white.withAlpha(0.7f));

     // add logo image
     auto logo = juce::ImageCache::getFromMemory(BinaryData::landon_png, BinaryData::landon_pngSize);
     auto logo_width = static_cast<int>(getWidth() * 0.2);
     auto logo_x = static_cast<int>(getWidth() * 0.01);
     auto logo_y = static_cast<int>(getWidth() * 0.003);
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

     _navbar.setBounds(compX, compY, compWidth, compHeight);

    compX = _navbar.getRight() + padding;
    compWidth = getWidth() * 0.095;
     _hqMenu.setBounds(compX, compY, compWidth, compHeight);

    compX = _hqMenu.getRight() + padding;
     _stereoMenu.setBounds(compX, compY, compWidth, compHeight);

    compWidth *= 0.5;
    compX = _stereoMenu.getRight() + padding;
    extras_button.setBounds(compX, compY, compWidth, compHeight);
    
    // if (getParentComponent() == nullptr) return;
    
    // if (auto parent = dynamic_cast<ViatorProcessorEditorCore*>(getParentComponent()) && !_mouseListenerAdded)
    // {
    //     _manualButton.addMouseListener(getParentComponent(), true);
    //     _navbar.getLoadButton().addMouseListener(getParentComponent(), true);
    //     _navbar.getSaveButton().addMouseListener(getParentComponent(), true);
    //     _mouseListenerAdded = true;
    // }
}

 void Header::setOversamplingMenuProps()
 {
     juce::StringArray choices = {"HQ Off", "HQ X2", "HQ X4", "HQ X8"};
     for (int i = 0; i < choices.size(); ++i)
     {
         _hqMenu.addItem(choices[i], i + 1);
     }
    
     _hqMenu.setMenuJustification(juce::Justification::centredLeft);
    
     addAndMakeVisible(_hqMenu);
     //_oversamplingAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getViatorTreeState(), ViatorParameters::oversamplingID, _hqMenu);
 }

 void Header::setStereoMenuProps()
 {
     juce::StringArray choices = {"Stereo", "Mono", "Mid", "Side"};
     for (int i = 0; i < choices.size(); ++i)
     {
         _stereoMenu.addItem(choices[i], i + 1);
     }
    
     _stereoMenu.setMenuJustification(juce::Justification::centredLeft);
    
     addAndMakeVisible(_stereoMenu);
     //_stereoAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getViatorTreeState(), ViatorParameters::stereoModeID, _stereoMenu);
     //_stereoMenu.setVisible(false);
 }

void Header::changeListenerCallback(juce::ChangeBroadcaster *source)
{
    // if (source == &_navbar)
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
    //_stereoMenu.setVisible(audioProcessor.getIsPluginStereo());
}

}
