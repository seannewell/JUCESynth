/*
  ==============================================================================

    SynthVoice.h
    Created: 6 Oct 2019 8:05:18pm
 
    **Shout out to this tutorial (https://www.youtube.com/watch?v=kxKEFTQRZPI)
    from The Audio Programmer for this file!**

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice
{
public:
    bool canPlaySound(SynthesiserSound* sound) {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //========================================================================
    
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWeelPosition){
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        level = velocity;
        std::cout << midiNoteNumber << "-" << frequency << std::endl;
    }
    
    //========================================================================
    
    void stopNote(float velocity, bool allowTailOff){
        
        level = 0;
        clearCurrentNote();
        
    }
    
    //========================================================================
    
    void pitchWheelMoved(int newPitchWheelValue){
        
    }
    
    
    //========================================================================
    
    
    void controllerMoved(int controllerNumber, int newControllerValue){
        
    }
    

    void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples){
        

        
        for (int sample = 0; sample < numSamples; ++sample) {

            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                outputBuffer.addSample(channel, startSample, 1); // '1' will be the output waveform
            }
            ++startSample;
        }
    }
    
    //========================================================================
    
private:
    double frequency;
    double level;
    
};
