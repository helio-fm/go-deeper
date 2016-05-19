/*
  ==============================================================================

    MidiTrainIteration.h
    Created: 20 Nov 2015 4:47:54pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#ifndef MIDITRAINITERATION_H_INCLUDED
#define MIDITRAINITERATION_H_INCLUDED

class MidiTrainIteration final
{
public:
    
    explicit MidiTrainIteration(TinyRNN::VMNetwork::Ptr targetNetwork);
    
    // Process one iteration of training.
    void processWith(const MidiMessageSequence &sortedSequence);
    
private:
    
    TinyRNN::VMNetwork::Ptr clNetwork;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiTrainIteration)
};

#endif  // MIDITRAINITERATION_H_INCLUDED
