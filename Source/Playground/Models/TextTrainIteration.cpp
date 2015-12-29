/*
  ==============================================================================

    TextTrainIteration.cpp
    Created: 8 Dec 2015 5:45:15pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "TextTrainIteration.h"

TextTrainIteration::TextTrainIteration(TinyRNN::HardcodedNetwork::Ptr targetNetwork) :
clNetwork(targetNetwork)
{
    // todo asserts for the number of neurons in input and output layers, etc
    jassert(targetNetwork->getContext()->getOutputs().size() == 32);
}

// Process one iteration of training.
void TextTrainIteration::processWith(const String &text)
{
    // todo
}
