/*
  ==============================================================================

    TextTrainIteration.h
    Created: 8 Dec 2015 5:45:15pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#ifndef TEXTTRAINITERATION_H_INCLUDED
#define TEXTTRAINITERATION_H_INCLUDED

class TextTrainIteration final
{
public:
    
#if defined TRAINING_MODE
    explicit TextTrainIteration();
#else
    explicit TextTrainIteration(TinyRNN::HardcodedNetwork::Ptr targetNetwork);
#endif
    
    // Process one iteration of training.
    void processWith(const String &text);
    String generateSample() const;
    
private:
    
#if not defined TRAINING_MODE
    TinyRNN::HardcodedNetwork::Ptr clNetwork;
#endif
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextTrainIteration)
};

#endif  // TEXTTRAINITERATION_H_INCLUDED
