#include "ExtrasPage.h"

namespace viator_core
{

ExtrasPage::ExtrasPage()
{
}

ExtrasPage::~ExtrasPage()
{
}

void ExtrasPage::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black.withAlpha(0.7f));

    g.setColour(juce::Colours::whitesmoke.withAlpha(0.2f));
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 6.0f, getWidth() * 0.01);
}

void ExtrasPage::resized()
{
}

}
