/*
  ==============================================================================

    BatchTextProcessor.cpp
    Created: 8 Dec 2015 5:45:02pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "BatchTextProcessor.h"

BatchTextProcessor::BatchTextProcessor(File targetsFolder,
                                       TinyRNN::HardcodedNetwork::Ptr targetNetwork) :
clNetwork(targetNetwork),
currentFileIndex(0),
memDumpIntervalSeconds(10.f)
{
    if (targetsFolder.isDirectory())
    {
        targetsFolder.findChildFiles(this->targetFiles,
                                     File::findFiles,
                                     true,
                                     "*.txt;*.xml");
    }
}

void BatchTextProcessor::start()
{
    // todo
}

void BatchTextProcessor::setDelegate(Delegate *targetDelegate)
{
    this->delegate = targetDelegate;
}
