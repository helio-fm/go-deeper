/*
  ==============================================================================

    TrainingPipeline.h
    Created: 7 Dec 2015 5:34:07pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#ifndef TRAININGPIPELINE_H_INCLUDED
#define TRAININGPIPELINE_H_INCLUDED

template <typename T>
class TrainingPipeline final : public T::Delegate
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
    
    ScopedPointer<T> processor;
    File memoryDumpFile;
};

template <typename T>
inline TrainingPipeline<T>::TrainingPipeline(TinyRNN::HardcodedNetwork::Ptr targetNetwork,
                                      File targetsFolder,
                                      File memDumpFile) :
memoryDumpFile(memDumpFile)
{
    this->processor = new T(targetsFolder, targetNetwork);
}

template <typename T>
inline TrainingPipeline<T>::~TrainingPipeline()
{
    this->processor = nullptr;
    
}

template <typename T>
inline void TrainingPipeline<T>::onDumpMemory(const String &memoryInBase64)
{
    std::cout << "Dumping the memory to " << this->memoryDumpFile.getFullPathName() << std::endl;
    this->memoryDumpFile.replaceWithText(memoryInBase64);
}

template <typename T>
inline bool TrainingPipeline<T>::shouldContinue(uint64 numIterationPassed)
{
    if (numIterationPassed % 1000 == 0)
    {
        std::cout << numIterationPassed << " iterations done." << std::endl;
    }
    
    return true;
}

template <typename T>
inline void TrainingPipeline<T>::start()
{
    this->processor->start();
}

#endif  // TRAININGPIPELINE_H_INCLUDED
