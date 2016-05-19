/*
  ==============================================================================

    BatchTextProcessor.h
    Created: 8 Dec 2015 5:45:02pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#ifndef BATCHTEXTPROCESSOR_H_INCLUDED
#define BATCHTEXTPROCESSOR_H_INCLUDED

class BatchTextProcessor final
{
public:
    
    BatchTextProcessor(File targetsFolder,
                       TinyRNN::HardcodedNetwork::Ptr targetNetwork,
                       uint64 iterationsCounter);
    
    class Delegate
    {
    public:
        virtual ~Delegate()
        { this->masterReference.clear(); }
        
        virtual void onDumpMemory(const String &memoryInBase64) = 0;
        virtual void onDumpSample(uint64 iteration, const String &sample) = 0;
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
    
    Array<File> targetFiles;
    int currentFileIndex;
    
    uint64 numIterations;
    float memDumpIntervalSeconds;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BatchTextProcessor)
};

#endif  // BATCHTEXTPROCESSOR_H_INCLUDED
