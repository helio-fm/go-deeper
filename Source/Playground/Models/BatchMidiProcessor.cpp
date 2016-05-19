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
                                       TinyRNN::VMNetwork::Ptr targetNetwork,
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
                                     "*.mid;*.midi;*.smf");
        
        this->currentFileIndex = iterationsCounter % this->targetFiles.size();
    }
}

static MidiMessageSequence loadMidiFile(File file)
{
    MidiFile midiFile;
    {
        ScopedPointer<FileInputStream> midiStream(file.createInputStream());
        midiFile.readFrom(*midiStream);
    }
    
    // merge all tracks
    MidiMessageSequence mergedSortedSequence;
    
    for (int i = 0; i < midiFile.getNumTracks(); ++i)
    {
        mergedSortedSequence.addSequence(*midiFile.getTrack(i),
                                         midiFile.getTrack(i)->getStartTime(),
                                         midiFile.getTrack(i)->getStartTime(),
                                         midiFile.getTrack(i)->getEndTime());
    }
    
    mergedSortedSequence.sort();
    return mergedSortedSequence;
}

void BatchMidiProcessor::setDelegate(Delegate *targetDelegate)
{
    this->delegate = targetDelegate;
}

void BatchMidiProcessor::start()
{
    uint32 lastDumpTimestamp = Time::getMillisecondCounter();
    bool shouldContinue = true;
    
    do
    {
        File currentFile(this->targetFiles[currentFileIndex]);
        
        // 1. get all the events
        const bool sequenceWasCached = this->loadedTracks.contains(currentFile.getFullPathName());
        const MidiMessageSequence &mergedSortedSequence =
        sequenceWasCached ? this->loadedTracks[currentFile.getFullPathName()] : loadMidiFile(currentFile);
        
        if (! sequenceWasCached)
        {
            this->loadedTracks.set(currentFile.getFullPathName(), mergedSortedSequence);
        }
        
        {
            // 2. process them with MidiTrainer
            TinyRNN::ScopedTimer timer("Training with " + currentFile.getFileName().toStdString());
            MidiTrainIteration midiTrainIteration(this->clNetwork);
            midiTrainIteration.processWith(mergedSortedSequence);
        }
        
        // 3. once X time passed, dump memory
        const uint32 millisecondsPassed = (Time::getMillisecondCounter() - lastDumpTimestamp);
        
        if (millisecondsPassed > (1000 * 60 * 10))
        {
            lastDumpTimestamp = Time::getMillisecondCounter();
            
            if (this->delegate != nullptr)
            {
                const String &memDump = this->dumpMemoryAsBase64();
                this->delegate->onDumpMemory(memDump);
            }
        }
        
        currentFileIndex = ((this->targetFiles.size() - 1) == currentFileIndex) ? 0 : (currentFileIndex + 1);
        this->numIterations++;
        
        if (this->delegate != nullptr)
        {
            shouldContinue = shouldContinue && this->delegate->shouldContinue(this->numIterations);
        }
        
    } while (shouldContinue);
}

String BatchMidiProcessor::dumpMemoryAsBase64()
{
    if (this->clNetwork != nullptr)
    {
        auto context = this->clNetwork->getContext();
        const std::string memoryEncoded =
        TinyRNN::SerializationContext::encodeBase64((const unsigned char *)context->getMemory().data(),
                                                    sizeof(double) * context->getMemory().size());
        return String(std::move(memoryEncoded));
    }
    
    return String::empty;
}
