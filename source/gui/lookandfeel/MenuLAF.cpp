#include "MenuLAF.h"

namespace viator_core
{
    CustomMenu::CustomMenu()
    {
        
    }

    void CustomMenu::drawComboBox (juce::Graphics& g, int width, int height, bool,
                                       int, int, int, int, juce::ComboBox& box)
    {
        auto cornerSize = 0.0f;
        juce::Rectangle<int> boxBounds (0, 0, width, height);

        auto bgColor = box.findColour (juce::ComboBox::backgroundColourId);
        g.setColour (bgColor);
        g.fillRoundedRectangle (boxBounds.toFloat(), cornerSize);

        g.setColour (box.findColour (juce::ComboBox::outlineColourId));
        g.drawRoundedRectangle (boxBounds.toFloat().reduced (0.5f, 0.5f), cornerSize, 1.0f);

        auto arrowWidth = height * 0.4;
        juce::Rectangle<int> arrowZone (width - arrowWidth * 1.5, 0, arrowWidth, height);
        juce::Path path;
        path.startNewSubPath ((float) arrowZone.getX() + arrowZone.getWidth() * 0.1, (float) arrowZone.getCentreY() - arrowZone.getHeight() * 0.05);
        path.lineTo ((float) arrowZone.getCentreX(), (float) arrowZone.getCentreY() + arrowZone.getHeight() * 0.1);
        path.lineTo ((float) arrowZone.getRight() - arrowZone.getWidth() * 0.1, (float) arrowZone.getCentreY() - arrowZone.getHeight() * 0.05);
        
        g.setColour(box.findColour(juce::ComboBox::textColourId));
        g.strokePath (path, juce::PathStrokeType (1.0f));
    }

    void CustomMenu::positionComboBoxText (juce::ComboBox& box, juce::Label& label)
    {
        label.setInterceptsMouseClicks(false, false);
        label.setBounds (box.getLocalBounds());
        label.setJustificationType(_justification);
        label.setFont (juce::Font("Helvetica", box.getHeight() * 0.5, juce::Font::FontStyleFlags::bold));
    }

void CustomMenu::drawComboBoxTextWhenNothingSelected (juce::Graphics& g, juce::ComboBox& box, juce::Label& label)
{
    g.setColour(box.findColour(juce::ComboBox::textColourId));
    auto font = label.getLookAndFeel().getLabelFont (label);

    g.setFont (font);

    auto textArea = label.getLocalBounds().withX(10);

    g.drawFittedText (box.getTextWhenNothingSelected(), textArea, label.getJustificationType(),
                      juce::jmax (1, (int) ((float) textArea.getHeight() / font.getHeight())),
                      label.getMinimumHorizontalScale());
}

void CustomMenu::drawPopupMenuItem (juce::Graphics& g, const juce::Rectangle<int>& area,
                                        const bool isSeparator, const bool isActive,
                                        const bool isHighlighted, const bool isTicked,
                                        const bool hasSubMenu, const juce::String& text,
                                        const juce::String& shortcutKeyText,
                                        const juce::Drawable* icon, const juce::Colour* const textColourToUse)
{
    if (isSeparator)
    {
        auto r = area.reduced (5, 0);
        r.removeFromTop (r.getHeight() / 2 - 1);

        g.setColour (juce::Colour (0x33000000));
        g.fillRect (r.removeFromTop (1));

        g.setColour (juce::Colour (0x66ffffff));
        g.fillRect (r.removeFromTop (1));
    }
    else
    {
        auto textColour = findColour (juce::PopupMenu::textColourId);

        if (textColourToUse != nullptr)
            textColour = *textColourToUse;

        auto r = area;

        if (isHighlighted)
        {
            g.setColour (findColour (juce::PopupMenu::highlightedBackgroundColourId));
            g.fillRect (r);

            g.setColour (findColour (juce::PopupMenu::highlightedTextColourId));
        }
        else
        {
            g.setColour (textColour);
        }

        if (! isActive)
            g.setOpacity (0.3f);

        juce::Font font (area.getHeight() * 0.5f);

        auto maxFontHeight = (float) area.getHeight() * 0.5f;

        if (font.getHeight() > maxFontHeight)
            font.setHeight (maxFontHeight);

        g.setFont (font);

        if (hasSubMenu)
        {
            auto arrowH = 0.6f * getPopupMenuFont().getAscent();

            auto x = (float) r.removeFromRight ((int) arrowH).getX();
            auto halfH = (float) r.getCentreY();

            juce::Path p;
            p.addTriangle (x, halfH - arrowH * 0.5f,
                           x, halfH + arrowH * 0.5f,
                           x + arrowH * 0.6f, halfH);

            g.fillPath (p);
        }

        r.removeFromRight (3);

        if (text == "User" || text == "Factory")
        {
            g.drawFittedText (text, r, juce::Justification::centred, 1);
        }

        else
        {
            g.drawFittedText (text, r.withX(static_cast<int>(area.getWidth() * 0.1)),
                              juce::Justification::centredLeft, 1);
        }

        if (shortcutKeyText.isNotEmpty())
        {
            juce::Font f2 (font);
            f2.setHeight (f2.getHeight() * 0.4f);
            f2.setHorizontalScale (0.95f);
            g.setFont (f2);

            g.drawText (shortcutKeyText, r, juce::Justification::centred, true);
        }
    }
}

void CustomMenu::drawPopupMenuBackground (juce::Graphics& g, int width, int height)
{
    auto background = findColour (juce::PopupMenu::backgroundColourId);
    g.fillAll (background);
}

void CustomMenu::getIdealPopupMenuItemSize (const juce::String& text, const bool isSeparator, int standardMenuItemHeight, int& idealWidth, int& idealHeight)
{
    if (isSeparator)
    {
        idealWidth = 50;
        idealHeight = standardMenuItemHeight > 0 ? standardMenuItemHeight / 2 : 10;
    }

    else
    {
        juce::Font font (getPopupMenuFont());

        if (standardMenuItemHeight > 0 && font.getHeight() > (float) standardMenuItemHeight / 1.3f)
        font.setHeight ((float) standardMenuItemHeight / 1.3f);

        idealHeight = standardMenuItemHeight > 0 ? standardMenuItemHeight : juce::roundToInt (font.getHeight() * 1.3f);
        idealWidth = font.getStringWidth (text) * 2.0;
    }
}

void CustomMenu::drawLabel (juce::Graphics& g, juce::Label& label)
{
    g.fillAll (label.findColour (juce::Label::backgroundColourId));

    if (! label.isBeingEdited())
    {
        auto alpha = label.isEnabled() ? 1.0f : 0.5f;
        const juce::Font font (getLabelFont (label));

        g.setColour (label.findColour (juce::Label::textColourId).withMultipliedAlpha (alpha));
        g.setFont (font);

        auto textArea = getLabelBorderSize (label).subtractedFrom (label.getLocalBounds());

        g.drawFittedText (label.getText(), textArea, _justification,
                          juce::jmax (1, (int) ((float) textArea.getHeight() / font.getHeight())),
                          label.getMinimumHorizontalScale());

        g.setColour (label.findColour (juce::Label::outlineColourId).withMultipliedAlpha (alpha));
    }
    
    else if (label.isEnabled())
    {
        g.setColour (label.findColour (juce::Label::outlineColourId));
    }

    g.drawRect (label.getLocalBounds());
}

}
