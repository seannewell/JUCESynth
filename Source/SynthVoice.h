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
    bool canPlaySound(Synthesiser* sound){
        
    }
    
    //==============================================================
    
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound,
                   int currentPitchWheelPosition){
        
    }
    //==============================================================

    void stopNote(float velocity, bool allowTailOff){
        
    }
    //==============================================================

    void pitchWheelMoved(int newPitchWheelValue){
        
    }
    //==============================================================
    
    void controllerMoved(int controllerNumber, int newControllerValue){
        
    }
    //==============================================================

    void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples){
        
    }
    //==============================================================
    
private:
    
    
    
    
    
};
