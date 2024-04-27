#include "ExtrasPage.h"

namespace viator_core
{

ExtrasPage::ExtrasPage()
{
    auto shadow_color = juce::Colours::black.withAlpha(0.15f);
    auto shadow = juce::DropShadow(shadow_color, 25, {});

    drop_shadow = std::make_unique<juce::DropShadower>(shadow);
    drop_shadow->setOwner(this);
}

ExtrasPage::~ExtrasPage()
{
}

void ExtrasPage::paint (juce::Graphics& g)
{
    g.setColour(viator_core::Colors::getViatorBGLightColor().withAlpha(0.8f));
    g.fillRect(0, 0, getWidth(), getHeight());
}

void ExtrasPage::resized()
{
}

}
