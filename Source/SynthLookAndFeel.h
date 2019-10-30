/*
  ==============================================================================

    SynthLookAndFeel.h
    Created: 23 Oct 2019 1:19:53pm
    Author:  Sean Newell

  ==============================================================================
*/

#ifndef SYNTHLOOKANDFEEL_H_INCLUDED
#define SYNTHLOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SynthLookAndFeel : public LookAndFeel_V4
{
public:
//    static constexpr float DefaultOutlineSize   = 1.0f;
//    static constexpr float DefaultCornerRadius  = 4.0f;
//    static constexpr float DisabledTransparency = 0.5f;
    static constexpr float DefaultFontSize      = 12.0f;
//    
    SynthLookAndFeel();
    
    Font getBaseFont ();
    Font getLabelFont (Label&) override;
    Font getSliderReadoutFont ();
    
    void drawLabel (Graphics&, Label&) override;
    
    void drawRotarySlider (Graphics&, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle,
                           Slider&) override;
    
    void drawLinearSlider(Graphics&, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider&) override;
    
};






#endif  // SYNTHLOOKANDFEEL_H_INCLUDED
