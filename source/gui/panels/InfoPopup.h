#pragma once
#ifndef InfoPopup_h
#define InfoPopup_h
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include "../lookandfeel/Colors.h"

namespace viator_core
{

class InfoPopup : public juce::Component
{
public:
    InfoPopup();
    ~InfoPopup() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    bool get_should_be_visible() {return should_be_visible;}

    void set_title_and_content(const juce::String& title, const juce::String& content);

private:

    std::unique_ptr<juce::DropShadower> drop_shadow;

    juce::Label title_label, content_label;
    void init_labels();

    bool should_be_visible {false};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InfoPopup)
};

}

#endif 
