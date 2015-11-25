/*
  ==============================================================================

    MidiTrainIteration.cpp
    Created: 20 Nov 2015 4:47:54pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "MidiTrainIteration.h"

MidiTrainIteration::MidiTrainIteration(TinyRNN::HardcodedNetwork::Ptr targetNetwork) :
clNetwork(targetNetwork)
{
    // todo asserts for the number of input layers, etc
    
    
    
    
}

// Process one iteration of training.
void MidiTrainIteration::processWith(const MidiMessageSequence &sequence)
{
    // 1. go through events and train the network
    // 2. unroll until the silence
    
    for (int i = 0; i < sequence.getNumEvents(); ++i)
    {
        //sequence.getEventPointer(i)->message
        //sequence.getEventPointer(i)->noteOffObject
        
        // get key
        // crop key range
        
        
    }
    
    
    
}
