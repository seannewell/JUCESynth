/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SynthLookAndFeel.h"

//==============================================================================
/**
*/
class JucesynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    JucesynthAudioProcessorEditor (JucesynthAudioProcessor&);
    ~JucesynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    SynthLookAndFeel laf;
    ScopedPointer<Slider> slider1;
    ScopedPointer<Slider> slider2;
    ScopedPointer<Label> label1;
    ScopedPointer<Drawable> drawable1;
    JucesynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JucesynthAudioProcessorEditor)
};
