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
    
    explicit TextTrainIteration(TinyRNN::VMNetwork::Ptr targetNetwork);
    
    // Process one iteration of training.
    void processWith(const String &text, uint64 iterationNumber);
    String generateSample() const;
    void test();
    
private:
    
    TinyRNN::VMNetwork::Ptr clNetwork;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextTrainIteration)
};

#endif  // TEXTTRAINITERATION_H_INCLUDED
