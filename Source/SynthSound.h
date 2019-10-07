/*
  ==============================================================================

    SynthSound.h
    Created: 6 Oct 2019 8:05:07pm
 
    **Shout out to this tutorial (https://www.youtube.com/watch?v=kxKEFTQRZPI)
        from The Audio Programmer for this file!**

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote(int /*midiNoteNumber*/){
        return true;
    }
    
    bool appliesToChannel(int /*midiChannel*/){
        return true;
    }
    
};

