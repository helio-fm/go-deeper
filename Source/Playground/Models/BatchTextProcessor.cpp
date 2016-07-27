/*
  ==============================================================================

    BatchTextProcessor.cpp
    Created: 8 Dec 2015 5:45:02pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "BatchTextProcessor.h"
#include "TextTrainIteration.h"

BatchTextProcessor::BatchTextProcessor(File targetsFolder,
                                       TinyRNN::UnrolledNetwork::Ptr targetNetwork,
                                       uint64 iterationsCounter) :
clNetwork(targetNetwork),
currentFileIndex(0),
numIterations(iterationsCounter),
memDumpIntervalSeconds(10.f)
{
    if (targetsFolder.isDirectory())
    {
        targetsFolder.findChildFiles(this->targetFiles,
                                     File::findFiles,
                                     true,
                                     "*.txt;*.xml");
        
        this->targetFiles.sort();
        this->currentFileIndex = iterationsCounter % this->targetFiles.size();
    }
}

static String loadTextSequence(File file)
{
    // simple as that
    return file.loadFileAsString();
}

static float rateForIteration(uint64 iterationNumber)
{
    if (iterationNumber < 100) {
        return 0.5f;
    }
    
    if (iterationNumber < 250) {
        return 0.2f;
    }
    
    return 0.05f;
}

void BatchTextProcessor::start()
{
    uint32 lastDumpTimestamp = Time::getMillisecondCounter();
    bool shouldContinue = true;
    const uint64 memoryDumpTimeout = (1000 * 60 * 15);
    const uint64 samplesDumpMaxIterations = 20;
    bool supervised = true;
    
    do
    {
        File currentFile(this->targetFiles[currentFileIndex]);
        
        // 1. get all the events
        const String textSequence = loadTextSequence(currentFile);
        TextTrainIteration textTrainIteration(this->clNetwork);
        
        if (supervised)
        {
            std::cout << "Enter the learning rate for this iteration (0 to continue in automatic mode): ";
            std::string userRate;
            std::getline(std::cin, userRate);
            float rate = stof(userRate);
            if (rate <= 0.f || rate >= 1.f)
            {
                supervised = false;
                rate = rateForIteration(this->numIterations);
            }
            
            TinyRNN::ScopedTimer timer("Training with " + currentFile.getFileName().toStdString());
            textTrainIteration.processWith(textSequence, rate);
        }
        else
        {
            // 2. process them with MidiTrainer
            TinyRNN::ScopedTimer timer("Training with " + currentFile.getFileName().toStdString());
            textTrainIteration.processWith(textSequence, rateForIteration(this->numIterations));
        }
        
        this->numIterations++;
        
        // 3. once X time passed, dump memory
        const uint32 millisecondsPassed = (Time::getMillisecondCounter() - lastDumpTimestamp);
        
        if (supervised ||
            millisecondsPassed > memoryDumpTimeout)
        {
            lastDumpTimestamp = Time::getMillisecondCounter();
            
            if (this->delegate != nullptr)
            {
                this->delegate->onDumpMemory(this->dumpMemoryAsBase64());
            }
        }
        
        if (supervised ||
            (this->numIterations % samplesDumpMaxIterations) == 0)
        {
            if (this->delegate != nullptr)
            {
                this->delegate->onDumpSample(this->numIterations,
                                             textTrainIteration.generateSample());
            }
        }
        
        currentFileIndex = ((this->targetFiles.size() - 1) == currentFileIndex) ? 0 : (currentFileIndex + 1);
        
        if (this->delegate != nullptr)
        {
            shouldContinue = shouldContinue && this->delegate->shouldContinue(this->numIterations);
        }
        
    } while (shouldContinue);
}

void BatchTextProcessor::setDelegate(Delegate *targetDelegate)
{
    this->delegate = targetDelegate;
}

String BatchTextProcessor::dumpMemoryAsBase64()
{
    if (this->clNetwork != nullptr)
    {
        auto context = this->clNetwork->getContext();
        const std::string memoryEncoded =
        TinyRNN::SerializationContext::encodeBase64((const unsigned char *)context->getMemory().data(),
                                                    sizeof(TinyRNN::Value) * context->getMemory().size());
        return String(std::move(memoryEncoded));
    }
    
    return String();
}
