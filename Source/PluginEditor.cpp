/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JucesynthAudioProcessorEditor::JucesynthAudioProcessorEditor (JucesynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setLookAndFeel(&laf);
    
    
    addAndMakeVisible (slider1 = new Slider ("Param1"));
    slider1->setRange (0, 100, 0);
    slider1->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider1->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    
    addAndMakeVisible (label1 = new Label ("Param1",
                                                  TRANS("PARAM1")));
    label1->setFont (Font (15.00f, Font::plain));
    label1->setJustificationType (Justification::centred);
    label1->setEditable (false, false, false);
    label1->setColour (Label::textColourId, Colour (0xffff8917));
    label1->setColour (TextEditor::textColourId, Colours::black);
    label1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (slider2 = new Slider ("Param2"));
    slider2->setRange (0, 100, 0);
    slider2->setSliderStyle (Slider::LinearVertical);
    slider2->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    
    setSize (700, 700);
}

JucesynthAudioProcessorEditor::~JucesynthAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void JucesynthAudioProcessorEditor::paint (Graphics& g)
{
    

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    //g.setColour (Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("JUCESynth!!!", getLocalBounds(), Justification::centred, 1);
    
    g.fillAll(Colours::whitesmoke);
}

void JucesynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    slider1->setBounds (28, 149, 72, 72);
    slider2->setBounds (28, 550, 30, 100);
    label1->setBounds (24, 111, 80, 20);
}
