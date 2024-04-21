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
    g.setColour(juce::Colours::black.withAlpha(0.7f));
    g.fillRoundedRectangle(0, 0, getWidth(), getHeight(), 6.0f);

    g.setColour(juce::Colours::whitesmoke.withAlpha(0.2f));
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 6.0f, 2.0f);
}

void ExtrasPage::resized()
{
}

}
