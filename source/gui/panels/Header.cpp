#include "Header.h"
#include "../../PluginProcessor.h"

namespace viator_core
{

Header::Header(PluginProcessor& p) : audioProcessor(p)//, _navbar(audioProcessor)
{
//     addAndMakeVisible(_navbar);
//     _navbar.addChangeListener(this);
    
//     _macroDial.addMouseListener(this, false);
//     _macroDial.setViatorTooltip("Macro dial to map in the settings window.");
//     //_macroAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getViatorTreeState(), "macroID", _macroDial);
//     addAndMakeVisible(_macroDial);
    
//     setOversamplingMenuProps();
//     setStereoMenuProps();
    
//     _manualButton.getButton().setButtonText("?");
//     _manualButton.setViatorTooltip("Opens/closes the included user manual for Duplex Comp.");
//     _manualButton.getButton().setColour(juce::TextButton::ColourIds::buttonColourId, viator_core::Colors::getViatorBGLightColor());
//     _manualButton.getButton().setColour(juce::ComboBox::ColourIds::outlineColourId, viator_core::Colors::getOutlineColor());
//     _manualButton.getButton().setColour(juce::TextButton::ColourIds::textColourOffId, viator_core::Colors::getViatorTextColor());
//     _manualButton.getButton().setColour(juce::TextButton::ColourIds::textColourOnId, viator_core::Colors::getViatorTextColor());
//     _manualButton.getButton().setClickingTogglesState(true);
//     addAndMakeVisible(_manualButton);
//     _manualButton.getButton().onClick = [this]()
//     {
//         getParentComponent()->resized();
//     };
    
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
    // auto x      = getWidth() * 0.285;
    // auto y      = getHeight() * 0.225;
    // auto width  = getWidth() * 0.45;
    // auto height = getHeight() * 0.55;
    // auto padding = getWidth() * 0.005;
    // _navbar.setBounds(x, y - 5, width, height + 10);
    
    // x = _navbar.getRight() + padding;
    // width = getWidth() * 0.065;
    // _hqMenu.setBounds(x, y, width, height);
    
    // x += width + padding;
    // _stereoMenu.setBounds(x, y, width, height);
    
    // width *= 0.5;
    // x = getWidth() - width - 10;
    // _manualButton.setBounds(x, y, width, height);
    
    // if (getParentComponent() == nullptr) return;
    
    // if (auto parent = dynamic_cast<ViatorProcessorEditorCore*>(getParentComponent()) && !_mouseListenerAdded)
    // {
    //     _manualButton.addMouseListener(getParentComponent(), true);
    //     _navbar.getLoadButton().addMouseListener(getParentComponent(), true);
    //     _navbar.getSaveButton().addMouseListener(getParentComponent(), true);
    //     _mouseListenerAdded = true;
    // }
}

// void Header::setOversamplingMenuProps()
// {
//     juce::StringArray choices = {"HQ Off", "HQ X2", "HQ X4", "HQ X8"};
//     for (int i = 0; i < choices.size(); ++i)
//     {
//         _hqMenu.addItem(choices[i], i + 1);
//     }
    
//     _hqMenu.setMenuJustification(juce::Justification::centredLeft);
    
//     addAndMakeVisible(_hqMenu);
//     //_oversamplingAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getViatorTreeState(), ViatorParameters::oversamplingID, _hqMenu);
// }

// void Header::setStereoMenuProps()
// {
//     juce::StringArray choices = {"Stereo", "Mono", "Mid", "Side"};
//     for (int i = 0; i < choices.size(); ++i)
//     {
//         _stereoMenu.addItem(choices[i], i + 1);
//     }
    
//     _stereoMenu.setMenuJustification(juce::Justification::centredLeft);
    
//     addAndMakeVisible(_stereoMenu);
//     //_stereoAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getViatorTreeState(), ViatorParameters::stereoModeID, _stereoMenu);
//     _stereoMenu.setVisible(false);
// }

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
