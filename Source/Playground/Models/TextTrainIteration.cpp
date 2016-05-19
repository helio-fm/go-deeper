/*
  ==============================================================================

    TextTrainIteration.cpp
    Created: 8 Dec 2015 5:45:15pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "TextTrainIteration.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define ALPHABET_RANGE 64

TextTrainIteration::TextTrainIteration(TinyRNN::VMNetwork::Ptr targetNetwork) :
clNetwork(targetNetwork)
{
    jassert(targetNetwork->getContext()->getOutputs().size() == ALPHABET_RANGE);
}

#pragma mark - ASCII bastardization

//int inputNodeIndexByChar192(juce_wchar character)
//{
//    int result = character;
//    
//    if (character >= 1040 &&
//        character <= 1104) {
//        result = 128 + (character - 1040);
//    }
//
//    return jmin(result, 192);
//}
//
//juce_wchar charByOutputNodeIndex192(int nodeIndex)
//{
//    juce_wchar result = nodeIndex;
//    
//    if (nodeIndex >= 128) {
//        result = (nodeIndex - 128) + 1040;
//    }
//    
//    return result;
//}
//
//static const int kCRReplacement = 36; // let's replace $ sign as the most useless on our case
//static const int kBaseAnchor = -32;
//static const int kCyrillicAnchor = 32;
//
//int inputNodeIndexByChar64(juce_wchar character)
//{
//    int result = character + kBaseAnchor;
//    
//    // All cyrillic UTF-8 symbols: 1040 to 1104 (0410h - 0450h) (64 in total)
//    // 0430 - 044F : lowercase cyrillic (32 in total)
//    // 1072 - 1103
//    
//    // handle cyrillic symbols (ignoring case)
//    if (character >= 1040 &&
//        character <= 1071) {
//        result = kCyrillicAnchor + (character - 1040);
//    }
//    
//    if (character >= 1072 &&
//        character <= 1103) {
//        result = kCyrillicAnchor + (character - 1072);
//    }
//    
//    // handle cr lf
//    if (character == 10 ||
//        character == 13) {
//        result = kCRReplacement + kBaseAnchor;
//    }
//    
//    return jmin(result, 64);
//}
//
//juce_wchar charByOutputNodeIndex64(int nodeIndex)
//{
//    juce_wchar result = nodeIndex - kBaseAnchor;
//    
//    // handle cyrillic symbols
//    if (nodeIndex >= kCyrillicAnchor) {
//        result = (nodeIndex + 1072 - kCyrillicAnchor);
//    }
//    
//    // handle cr lf
//    if (result == kCRReplacement) {
//        result = 10;
//    }
//    
//    return result;
//}


int inputNodeIndexByChar40(juce_wchar character)
{
    if (character >= 1072 &&
        character <= 1103) {
        return (character - 1072);
    }
    
    switch (character)
    {
        case 10:
        case 13:        // Linebreak
            return 33;
        case 32:        // Space
            return 34;
        case 33:        // !
            return 35;
        case 34:        // "
            return 36;
        case 44:        // ,
            return 37;
        case 46:        // .
            return 38;
        case 63:        // ?
            return 39;
    }
    
    return 0;
}

juce_wchar charByOutputNodeIndex40(int nodeIndex)
{
    // handle cyrillic symbols
    if (nodeIndex < 32) {
        return (nodeIndex + 1072);
    }
    
    switch (nodeIndex)
    {
        case 33:
            return 10;
        case 34:        // Space
            return 32;
        case 35:        // !
            return 33;
        case 36:        // "
            return 34;
        case 37:        // ,
            return 44;
        case 38:        // .
            return 46;
        case 39:        // ?
            return 63;
    }

    return 0;
}

//#pragma mark - Test
//
//void TextTrainIteration::test()
//{
//    std::cout << "Encoding test" << std::endl;
//    
//    for (juce_wchar i = 0; i < 128; ++i) {
//        std::cout << std::to_string(inputNodeIndexByChar64(i)) << " ";
//    }
//
//    std::cout << std::endl << "Encoding test" << std::endl;;
//    
//    for (juce_wchar i = 1072; i < 1104; ++i) {
//        std::cout << std::to_string(inputNodeIndexByChar64(i)) << " ";
//    }
//
//    std::cout << std::endl << "Decoding test" << std::endl;;
//    
//    for (size_t i = 0; i < ALPHABET_RANGE; ++i) {
//        std::cout << charByOutputNodeIndex64(i) << " ";
//    }
//    
//    std::cout << std::endl << "Decoding test 2" << std::endl;;
//    String result;
//    
//    for (size_t i = 0; i < ALPHABET_RANGE; ++i) {
//        result += charByOutputNodeIndex64(i);
//        result += " ";
//    }
//    
//    std::cout << result.toStdString() << std::endl;;
//}


#pragma mark - Processing

float rateForIteration(uint64 iterationNumber)
{
    if (iterationNumber < 100) {
        return 1.f;
    }
    
    if (iterationNumber < 250) {
        return 0.75f;
    }
    
    if (iterationNumber < 500) {
        return 0.5f;
    }
    
    return 0.2f;
}

// Process one iteration of training.
void TextTrainIteration::processWith(const String &text, uint64 iterationNumber)
{
    // 1. go through events and train the network
    
    int currentCharIndex = 0;
    const float rate = rateForIteration(iterationNumber);
    
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
        
        std::fill(inputs.begin(), inputs.end(), 0.f);
        int currentCharNodeIndex = inputNodeIndexByChar40(text[currentCharIndex]);
        for (int i = 0; i < ALPHABET_RANGE; ++i)
        {
            inputs[i] = (i == currentCharNodeIndex) ? 1.f : 0.f;
        }
        
        // now fix the targets
        std::fill(targets.begin(), targets.end(), 0.f);
        const bool isLastChar = (currentCharIndex == (text.length() - 1));
        int nextCharNodeIndex = isLastChar ? inputNodeIndexByChar40('\n') : inputNodeIndexByChar40(text[currentCharIndex + 1]);
        for (int i = 0; i < ALPHABET_RANGE; ++i)
        {
            targets[i] = (i == nextCharNodeIndex) ? 1.f : 0.f;
        }
        
        // train
        this->clNetwork->feed(inputs);
        this->clNetwork->train(rate, targets);
        
        currentCharIndex++;
    }
    
    // train with some empty passes
    static const size_t emptyTrainIterations = 20;
    std::fill(inputs.begin(), inputs.end(), 0.f);
    std::fill(targets.begin(), targets.end(), 0.f);
    
    for (size_t i = 0; i < emptyTrainIterations; ++i)
    {
        this->clNetwork->feed(inputs);
        this->clNetwork->train(rate, targets);
    }
}

String TextTrainIteration::generateSample() const
{
    srand(time(NULL));
    
    const int seedLength = 30;
    TinyRNN::HardcodedTrainingContext::RawData inputs;
    inputs.resize(ALPHABET_RANGE);
    
    for (int i = 0; i < seedLength; ++i)
    {
        std::fill(inputs.begin(), inputs.end(), 0.f);
        const int randomChar = (rand() % 32);
        inputs[randomChar] = 1.f;
        this->clNetwork->feed(inputs);
    }
    
    String result;
    const int sampleLength = 1000;
    
    for (int i = 0; i < sampleLength; ++i)
    {
        const auto &outputs = this->clNetwork->feed(inputs);
        
        int charIndex = 0;
        int charIndex2 = 0;
        float maxProbability = -FLT_MAX;
        for (int j = 0; j < outputs.size(); ++j)
        {
            if (maxProbability < outputs[j])
            {
                maxProbability = outputs[j];
                charIndex2 = charIndex;
                charIndex = j;
            }
        }
        
        const int random = (rand() % 10);
        const int finalIndex = ((random > 5) && (charIndex2 > 0)) ? charIndex2 : charIndex;
        result += charByOutputNodeIndex40(finalIndex);
        
        std::fill(inputs.begin(), inputs.end(), 0.f);
        inputs[finalIndex] = 1.f;
        //memcpy(inputs.data(), outputs.data(), sizeof(TinyRNN::Value) * outputs.size());
    }
    
    static const size_t emptyFeedIterations = 10;
    std::fill(inputs.begin(), inputs.end(), 0.f);
    for (size_t i = 0; i < emptyFeedIterations; ++i)
    {
        this->clNetwork->feed(inputs);
    }
    
    return result;
}
