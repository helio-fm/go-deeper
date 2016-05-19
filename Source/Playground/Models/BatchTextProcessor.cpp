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

#if defined TRAINING_MODE
#include "GoDeeper.h"
#endif

BatchTextProcessor::BatchTextProcessor(File targetsFolder,
                                       TinyRNN::HardcodedNetwork::Ptr targetNetwork,
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
        
        this->currentFileIndex = iterationsCounter % this->targetFiles.size();
    }
}

static String loadTextSequence(File file)
{
    // simple as that
    return file.loadFileAsString();
}

void BatchTextProcessor::start()
{
    uint32 lastDumpTimestamp = Time::getMillisecondCounter();
    bool shouldContinue = true;
    const uint64 memoryDumpTimeout = (1000 * 60 * 15);
    const uint64 samplesDumpMaxIterations = 20;
    
    do
    {
        File currentFile(this->targetFiles[currentFileIndex]);
        
        // 1. get all the events
        const String textSequence = loadTextSequence(currentFile);
        
#if defined TRAINING_MODE
        TextTrainIteration textTrainIteration;
#else
        TextTrainIteration textTrainIteration(this->clNetwork);
#endif
        
        {
            // 2. process them with MidiTrainer
            TinyRNN::ScopedTimer timer("Training with " + currentFile.getFileName().toStdString());
            textTrainIteration.processWith(textSequence, this->numIterations);
        }
        
        this->numIterations++;
        
        // 3. once X time passed, dump memory
        const uint32 millisecondsPassed = (Time::getMillisecondCounter() - lastDumpTimestamp);
        
        if (millisecondsPassed > memoryDumpTimeout)
        {
            lastDumpTimestamp = Time::getMillisecondCounter();
            
            if (this->delegate != nullptr)
            {
                this->delegate->onDumpMemory(this->dumpMemoryAsBase64());
            }
        }
        
        if ((this->numIterations % samplesDumpMaxIterations) == 0)
        {
            if (this->delegate != nullptr)
            {
                this->delegate->onDumpSample(this->numIterations, textTrainIteration.generateSample());
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
#if defined TRAINING_MODE
    return
    String(std::move(TinyRNN::SerializationContext::encodeBase64((const unsigned char *)kMemory, sizeof(float) * kMemorySize)));
#else
    if (this->clNetwork != nullptr)
    {
        auto context = this->clNetwork->getContext();
        const std::string memoryEncoded =
        TinyRNN::SerializationContext::encodeBase64((const unsigned char *)context->getMemory().data(),
                                                    sizeof(double) * context->getMemory().size());
        return String(std::move(memoryEncoded));
    }
#endif
}
