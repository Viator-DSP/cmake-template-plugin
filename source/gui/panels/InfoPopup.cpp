#include "InfoPopup.h"

namespace viator_core
{

InfoPopup::InfoPopup()
{
    drop_shadow = std::make_unique<juce::DropShadower>(juce::DropShadow(juce::Colours::black.withAlpha(0.5f), 10, {}));
    drop_shadow->setOwner(this);

    init_labels();
}

InfoPopup::~InfoPopup()
{
    drop_shadow.reset();
}

void InfoPopup::paint (juce::Graphics& g)
{
    auto width = static_cast<float>(getWidth());
    auto height = static_cast<float>(getHeight());
    g.setColour(viator_core::Colors::getPrimaryBGColor().withAlpha(0.8f));
    g.fillRoundedRectangle(0, 0, width, height, 6.0f);

    g.setColour(viator_core::Colors::getOutlineColor());
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 6.0f, 2.0f);
    g.drawLine(static_cast<float>(width * 0.05),
               static_cast<float>(height * 0.33),
               static_cast<float>(width * 0.95),
               static_cast<float>(height * 0.33),
               2.0f);
}

void InfoPopup::resized()
{
    auto compX = static_cast<int>(getWidth() * 0.1);
    auto compY = static_cast<int>(getHeight() * 0.0);
    auto compWidth = static_cast<int>(getWidth() * 0.8);
    auto compHeight = static_cast<int>(getHeight() * 0.33);
    auto font_size = static_cast<float>(compHeight) * 0.5f;
    title_label.setBounds(compX, compY, compWidth, compHeight);
    title_label.setFont(juce::Font("Helvetica", font_size, juce::Font::FontStyleFlags::plain));

    compX = static_cast<int>(getWidth() * 0.05);
    compY = static_cast<int>(getHeight() * 0.35);
    compWidth = static_cast<int>(getWidth() * 0.9);
    compHeight = static_cast<int>(getHeight() * 0.65);
    content_label.setBounds(compX, compY, compWidth, compHeight);
    content_label.setFont(juce::Font("Helvetica", font_size * 0.6f, juce::Font::FontStyleFlags::plain));
}

void InfoPopup::init_labels()
{
    title_label.setJustificationType(juce::Justification::centred);
    title_label.setColour(juce::Label::ColourIds::textColourId,
                          viator_core::Colors::getPrimaryAccentColor().brighter(0.2).withAlpha(0.7f));
    addAndMakeVisible(title_label);

    content_label.setJustificationType(juce::Justification::centredLeft);
    content_label.setColour(juce::Label::ColourIds::textColourId,
                            viator_core::Colors::getViatorTextColor().withAlpha(0.7f));
    addAndMakeVisible(content_label);
}

void InfoPopup::set_title_and_content(const juce::String &title, const juce::String &content)
{
    title_label.setText(title, juce::dontSendNotification);
    content_label.setText(content, juce::dontSendNotification);
}

}
