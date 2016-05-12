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
                     File samplesDumpFolder,
                     File memDumpFile);
    
    virtual ~TrainingPipeline() override;
    
    virtual void onDumpMemory(const String &memoryInBase64) override;
    virtual void onDumpSample(uint64 iteration, const String &sample) override;
    virtual bool shouldContinue(uint64 numIterationPassed) override;
    
    void start();
    
private:
    
    ScopedPointer<T> processor;
    File samplesDumpFolder;
    File memoryDumpFile;
    
};

template <typename T>
inline TrainingPipeline<T>::TrainingPipeline(TinyRNN::HardcodedNetwork::Ptr targetNetwork,
                                             File targetsFolder,
                                             File samplesDumpFolder,
                                             File memoryDumpFile) :
samplesDumpFolder(samplesDumpFolder),
memoryDumpFile(memoryDumpFile)
{
    this->samplesDumpFolder.createDirectory();
    
    uint64 startingNumIterations = 0;
    
    // Attempt to determine the latest training iteration 
    Array<File> sampleFiles;
    this->samplesDumpFolder.findChildFiles(sampleFiles,
                                           File::findFiles,
                                           true,
                                           "*.*");
    for (const auto &file : sampleFiles)
    {
        StringArray fileNameParts =
        StringArray::fromTokens(file.getFileName(), " _.", "");
        for (const auto &fileNamePart : fileNameParts)
        {
            startingNumIterations = jmax(startingNumIterations, uint64(fileNamePart.getLargeIntValue()));
        }
    }
    
    std::cout << "Training from " << std::to_string(startingNumIterations) << " iteration." << std::endl;
    this->processor = new T(targetsFolder, targetNetwork, startingNumIterations);
    this->processor->setDelegate(this);
}

template <typename T>
inline TrainingPipeline<T>::~TrainingPipeline()
{
    this->processor->setDelegate(nullptr);
    this->processor = nullptr;
}

template <typename T>
inline void TrainingPipeline<T>::onDumpMemory(const String &memoryInBase64)
{
    std::cout << "Dumping the memory to " << this->memoryDumpFile.getFullPathName() << std::endl;
    this->memoryDumpFile.replaceWithText(memoryInBase64);
}

template <typename T>
inline void TrainingPipeline<T>::onDumpSample(uint64 iteration, const String &sample)
{
    std::cout << "Dumping the sample of iteration " << iteration << std::endl << std::endl;
    
    File sampleDumpFile = this->samplesDumpFolder.getChildFile("sample_iteration_" + String(iteration));
    sampleDumpFile.replaceWithText(sample);
    
    std::cout << sample << std::endl << std::endl;
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
