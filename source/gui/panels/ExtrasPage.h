#pragma once
#ifndef ExtrasPage_h
#define ExtrasPage_h
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include "../lookandfeel/Colors.h"

namespace viator_core
{

class ExtrasPage : public juce::Component
{
public:
    ExtrasPage();
    ~ExtrasPage() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
private:

    std::unique_ptr<juce::DropShadower> drop_shadow;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ExtrasPage)
};

}

#endif 
