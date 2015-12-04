/*
  ==============================================================================

    BatchMidiProcessor.h
    Created: 20 Nov 2015 4:48:13pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#ifndef BATCHMIDIPROCESSOR_H_INCLUDED
#define BATCHMIDIPROCESSOR_H_INCLUDED

class BatchMidiProcessor final
{
public:
    
    BatchMidiProcessor(File targetsFolder,
                       TinyRNN::HardcodedNetwork::Ptr targetNetwork);
    
    class Delegate
    {
    public:
        virtual ~Delegate()
        { this->masterReference.clear(); }
        
        virtual void onDumpMemory(const String &memoryInBase64) = 0;
        virtual bool shouldContinue(uint64 numIterationPassed) = 0;
        
    private:
        WeakReference<Delegate>::Master masterReference;
        friend class WeakReference<Delegate>;
    };
    
    void start();
    void setDelegate(Delegate *delegate);
    
private:
    
    String dumpMemoryAsBase64();
    
    TinyRNN::HardcodedNetwork::Ptr clNetwork;
    WeakReference<Delegate> delegate;
    
    // do we need this?
    // maybe use but limit by the size?
    // most of the ram will be consumed by the network?
    HashMap<String, MidiMessageSequence> loadedTracks;
    
    Array<File> targetFiles;
    int currentFileIndex;
    
    float memDumpIntervalSeconds;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BatchMidiProcessor)
};

#endif  // BATCHMIDIPROCESSOR_H_INCLUDED
