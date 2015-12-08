/*
  ==============================================================================

    TrainingPipeline.cpp
    Created: 7 Dec 2015 5:34:07pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "TrainingPipeline.h"

TrainingPipeline::TrainingPipeline(TinyRNN::HardcodedNetwork::Ptr targetNetwork,
                                   File targetsFolder,
                                   File memDumpFile) :
memoryDumpFile(memDumpFile)
{
    this->processor = new BatchMidiProcessor(targetsFolder, targetNetwork);
}

TrainingPipeline::~TrainingPipeline()
{
    this->processor = nullptr;
    
}

void TrainingPipeline::onDumpMemory(const String &memoryInBase64)
{
    std::cout << "Dumping the memory to " << this->memoryDumpFile.getFullPathName() << std::endl;
    this->memoryDumpFile.replaceWithText(memoryInBase64);
}

bool TrainingPipeline::shouldContinue(uint64 numIterationPassed)
{
    if (numIterationPassed % 1000 == 0)
    {
        std::cout << numIterationPassed << " iterations done." << std::endl;
    }
    
    return true;
}

void TrainingPipeline::start()
{
    this->processor->start();
}
