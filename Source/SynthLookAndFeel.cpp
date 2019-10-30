/*
  ==============================================================================

    SynthLookAndFeel.cpp
    Created: 23 Oct 2019 1:19:53pm
    Author:  Sean Newell

  ==============================================================================
*/

#include "SynthLookAndFeel.h"

SynthLookAndFeel::SynthLookAndFeel()
{
    setColour(Slider::rotarySliderFillColourId, Colour::fromRGBA(255, 255, 255, 255));
}

Font SynthLookAndFeel::getBaseFont()
{
    return Font(Typeface::createSystemTypefaceFor(Font ("Didot", DefaultFontSize, Font::plain)));
    //return Font().withHeight(DefaultFontSize).boldened();
}

Font SynthLookAndFeel::getLabelFont(Label &)
{
    return getBaseFont().withPointHeight(10);
}

Font SynthLookAndFeel::getSliderReadoutFont()
{
    return getBaseFont().withPointHeight(14);
}

void SynthLookAndFeel::drawLabel(Graphics& g, Label& l)
{
    Colour labelColour = Colour::fromRGB(0, 0, 0);
    Font labelFont = getLabelFont(l);
    
    g.setColour(labelColour);
    g.setFont(labelFont);
    
    Rectangle<int> textArea (l.getBorderSize().subtractedFrom (l.getLocalBounds()));
    
    g.drawFittedText (l.getText(), textArea, l.getJustificationType(),
                      jmax (1, (int) (textArea.getHeight() / labelFont.getHeight())),
                      l.getMinimumHorizontalScale());
}

void SynthLookAndFeel::drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider){
    
    const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();

    // Draw the track
    g.setColour(Colour::fromRGB(78, 11, 200));
    Path track;
    track.addRectangle(x, y, width, maxSliderPos);
    g.strokePath(track, PathStrokeType(8.0f));

    // Draw the slider position
    Colour sliderFillStart = Colour::fromRGBA(245, 121, 35, 255).withAlpha(isMouseOver ? 1.0f : 0.9f);
    Colour sliderFillStop = Colour::fromRGBA(255, 184, 23, 255).withAlpha(isMouseOver ? 1.0f : 0.9f);
    ColourGradient sliderFill = ColourGradient(sliderFillStart,
                                               (float) x,
                                               (float) 0,
                                               sliderFillStop,
                                               (float) width,
                                               (float) 0,
                                               false);

    g.setGradientFill(sliderFill);

    Path filledLine;
    filledLine.addRectangle(x, y, width, sliderPos);

    //g.strokePath(filledLine, PathStrokeType(8.0f));
    PathStrokeType(8.0f).createStrokedPath(filledLine, filledLine);
    g.fillPath(filledLine);
    

    
}

void SynthLookAndFeel::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                          const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider){
    const float radius = jmin (width / 2, height / 2) - 2.0f;
    const float centreX = x + width * 0.5f;
    const float centreY = y + height * 0.5f;
    const float rx = centreX - radius;
    const float ry = centreY - radius;
    const float rw = radius * 2.0f;
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
    
    //Draw slider background
    g.setColour(Colour::fromRGB(78, 11, 200));
    //g.drawEllipse(x, y, width, height, .6);
    g.fillEllipse(x, y, width, height);
    //g.fillAll();
    
    // Draw the readout
    Colour readoutColour = Colour::fromRGB(254, 173, 29).withAlpha(isMouseOver ? 1.0f : 0.9f);
    const double value = slider.getValue();
    String readoutValue = (value >= 1000.0 ? String(value / 1000.0, 1) + "k" : String(value, 1));
    String readout = readoutValue + slider.getTextValueSuffix();
    
    g.setColour(readoutColour);
    g.drawText(readout, centreX - radius, centreY - 10.0f, rw, 24.0f, Justification::centred);
    
    // Draw the track
    g.setColour (slider.findColour (Slider::rotarySliderOutlineColourId));
    
    Path track;
    track.addArc(rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, true);
    g.strokePath(track, PathStrokeType(3.0f));
    
    // Draw the slider position
    Colour sliderFillStart = Colour::fromRGBA(245, 121, 35, 255).withAlpha(isMouseOver ? 1.0f : 0.9f);
    Colour sliderFillStop = Colour::fromRGBA(255, 184, 23, 255).withAlpha(isMouseOver ? 1.0f : 0.9f);
    ColourGradient sliderFill = ColourGradient(sliderFillStart,
                                               (float) x,
                                               (float) 0,
                                               sliderFillStop,
                                               (float) width,
                                               (float) 0,
                                               false);
    
    g.setGradientFill(sliderFill);
    
    Path filledArc;
    filledArc.addArc(rx, ry, rw, rw, rotaryStartAngle, angle, true);
    PathStrokeType(3.0f).createStrokedPath(filledArc, filledArc);
    g.fillPath(filledArc);
    
    
}
