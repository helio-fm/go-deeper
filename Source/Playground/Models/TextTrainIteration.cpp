/*
  ==============================================================================

    TextTrainIteration.cpp
    Created: 8 Dec 2015 5:45:15pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "TextTrainIteration.h"

#if defined TRAINING_MODE
#include "GoDeeper.h"
#endif

#if defined TRAINING_MODE
TextTrainIteration::TextTrainIteration() {}
#else
TextTrainIteration::TextTrainIteration(TinyRNN::HardcodedNetwork::Ptr targetNetwork) :
clNetwork(targetNetwork)
{
    // todo asserts for the number of neurons in input and output layers, etc
    jassert(targetNetwork->getContext()->getOutputs().size() == 35);
}
#endif

int inputNodeIndexByChar(juce_wchar character)
{
    // TODO(peterrudenko) minimize inputs and outputs at any cost?
    
    
    int result = character;
    
    if (character >= 1040 &&
        character <= 1104) {
        result = 128 + (character - 1040);
    }
    
    // Okay, here we need ASCII symbols from 0 to 128
    // And russian cyrillic UTF-8 symbols from 1040 to 1104 (0410h - 0450h) (64 totally)
    // 196 input and output nodes in total - ok?
    
    return jmin(result, 192);
}

juce_wchar charByOutputNodeIndex(int nodeIndex)
{
    juce_wchar result = nodeIndex;
    
    if (nodeIndex >= 128) {
        result = (nodeIndex - 128) + 1040;
    }
    
    return result;
}

#define ALPHABET_RANGE 160

// Process one iteration of training.
void TextTrainIteration::processWith(const String &text)
{
    // 1. go through events and train the network
    
    int currentCharIndex = 0;
    
    // presuming that we have a lstm like
    // ALPHABET_RANGE -> ... -> ALPHABET_RANGE
    
    TinyRNN::HardcodedTrainingContext::RawData inputs;
    inputs.resize(ALPHABET_RANGE);
    
    TinyRNN::HardcodedTrainingContext::RawData targets;
    targets.resize(ALPHABET_RANGE);
    
    while (currentCharIndex < text.length())
    {
        // inputs and outputs are the float vectors of size ALPHABET_RANGE
        // inputs define the current character
        // outputs define the one to come next
        
        inputs.clear();
        int currentCharNodeIndex = inputNodeIndexByChar(text[currentCharIndex]);
        for (int i = 0; i < ALPHABET_RANGE; ++i)
        {
            inputs[i] = (i == currentCharNodeIndex) ? 1.f : 0.f;
        }
        
        // now fix the targets
        targets.clear();
        const bool isLastChar = (currentCharIndex == (text.length() - 1));
        int nextCharNodeIndex = isLastChar ? inputNodeIndexByChar('\n') : inputNodeIndexByChar(currentCharIndex + 1);
        for (int i = 0; i < ALPHABET_RANGE; ++i)
        {
            targets[i] = (i == nextCharNodeIndex) ? 1.f : 0.f;
        }
        
        // train
#if defined TRAINING_MODE
        GoDeeperFeed(inputs.data());
        GoDeeperTrain(0.5f, targets.data());
#else
        this->clNetwork->feed(inputs);
        this->clNetwork->train(0.5, targets);
#endif
        
        currentCharIndex++;
    }
}

String TextTrainIteration::generateSample() const
{
#if defined TRAINING_MODE
    String result;
    const int sampleLength = 2000;
    for (int i = 0; i < sampleLength; ++i)
    {
        GoDeeperFeed(kOutputs);
        
        int charIndex = 0;
        float maxProbability = -FLT_MAX;
        for (int j = 0; j < kOutputsSize; ++j)
        {
            if (maxProbability < kOutputs[j])
            {
                maxProbability = kOutputs[j];
                charIndex = j;
            }
        }
        
        result += charByOutputNodeIndex(charIndex);
    }
    
    return result;
#else
    return String::empty;
#endif
}
