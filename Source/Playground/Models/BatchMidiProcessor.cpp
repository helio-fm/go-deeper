/*
  ==============================================================================

    BatchMidiProcessor.cpp
    Created: 20 Nov 2015 4:48:13pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "BatchMidiProcessor.h"
#include "MidiTrainIteration.h"

BatchMidiProcessor::BatchMidiProcessor(File targetsFolder,
                                       TinyRNN::HardcodedNetwork::Ptr targetNetwork) :
clNetwork(targetNetwork),
currentFileIndex(0),
memDumpIntervalSeconds(10.f)
{
    // parse targets folder for midi files
    // and fill up the array
    
    // todo asserts for the number of input layers, etc
}

void BatchMidiProcessor::process()
{
    MidiTrainIteration midiTrainIteration(this->clNetwork);
    
    // 1. load the midi from the file with the next index
    
    // 2. process with MidiTrainer
    //TinyRNN::ScopedTimer timer("Training with " + currentFile.getFileName());
    
    // 3. once the N iterations (or X time) passed, dump memory and - what? save? pass to the delegate? throw an event?
    
    
    
    //midiTrainIteration.processWith();
    
}

String BatchMidiProcessor::dumpMemoryAsBase64()
{
    auto context = this->clNetwork->getContext();
    const std::string memoryEncoded =
    TinyRNN::SerializationContext::encodeBase64((const unsigned char *)context->getMemory().data(),
                                                sizeof(double) * context->getMemory().size());
    return String(memoryEncoded);
}
