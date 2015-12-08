/*
  ==============================================================================

    TrainingPipeline.h
    Created: 7 Dec 2015 5:34:07pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#ifndef TRAININGPIPELINE_H_INCLUDED
#define TRAININGPIPELINE_H_INCLUDED

#include "BatchMidiProcessor.h"

class TrainingPipeline : public BatchMidiProcessor::Delegate
{
public:
    
    TrainingPipeline(TinyRNN::HardcodedNetwork::Ptr targetNetwork,
                     File targetsFolder,
                     File memDumpFile);
    
    virtual ~TrainingPipeline() override;
    
    virtual void onDumpMemory(const String &memoryInBase64) override;
    virtual bool shouldContinue(uint64 numIterationPassed) override;
    
    void start();
    
private:
    
    ScopedPointer<BatchMidiProcessor> processor;
    
    File memoryDumpFile;
    
};



#endif  // TRAININGPIPELINE_H_INCLUDED
