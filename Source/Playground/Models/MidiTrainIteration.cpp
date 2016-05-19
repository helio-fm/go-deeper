/*
  ==============================================================================

    MidiTrainIteration.cpp
    Created: 20 Nov 2015 4:47:54pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "MidiTrainIteration.h"

#define KEY_RANGE 64

MidiTrainIteration::MidiTrainIteration(TinyRNN::HardcodedNetwork::Ptr targetNetwork) :
clNetwork(targetNetwork)
{
    jassert(targetNetwork->getContext()->getOutputs().size() == KEY_RANGE);
}

static int midiKeyToArperRangeKey(int midiKey)
{
    // from 32 to (32 + 64)
    // wrap others into that range by transponing
    
    int result = midiKey;
    int lowestNote = 32;
    int highestNote = (lowestNote + KEY_RANGE);
    
    if (midiKey <= lowestNote)
    {
        const int numOctavesToTranspose = ((lowestNote - midiKey) / 12) + 1;
        result = midiKey + (12 * numOctavesToTranspose);
    }
    else if (midiKey > highestNote)
    {
        const int numOctavesToTranspose = ((midiKey - highestNote) / 12) + 1;
        result = midiKey - (12 * numOctavesToTranspose);
    }
    
    result = result - midiKey;
    
    jassert(result >= 0);
    jassert(result < KEY_RANGE);
    
    return result;
}

static int arperRangeKeyToMidiKey(int arperRangeKey)
{
    
}

// Process one iteration of training.
void MidiTrainIteration::processWith(const MidiMessageSequence &sortedSequence)
{
    // 1. go through events and train the network
    
    // input:
    // holding chords
    // x[64]
    
    // output:
    // probability of every note's on
    // x[64]
    
    long long currentTick = (long long)sortedSequence.getStartTime();
    const long long lastTick = (long long)sortedSequence.getEndTime();
    
    int currentEventIndex = 0;
    
    // presuming that we have a lstm like 128 -> ... -> 128
    
    TinyRNN::HardcodedTrainingContext::RawData inputs;
    inputs.resize(KEY_RANGE);
    
    TinyRNN::HardcodedTrainingContext::RawData targets;
    targets.resize(KEY_RANGE);
    
    std::unordered_map<int, double> holdingNotes;
    
    while (currentTick <= lastTick)
    {
        // inputs and outputs are the float vectors of size 64
        // inputs contain holding notes
        // outputs contain note-ons
        
        std::fill(inputs.begin(), inputs.end(), 0.f);
        
        // fill up the inputs with current holding notes
        for (int i = 0; i < KEY_RANGE; ++i)
        {
            inputs[i] = holdingNotes[i];
        }
        
        // find all messages for the current tick
        Array<MidiMessage> messagesOfCurrentTick;
        for (int i = currentEventIndex; i < sortedSequence.getNumEvents(); ++i)
        {
            const auto &message = sortedSequence.getEventPointer(i)->message;
            const long long tick = (long long)message.getTimeStamp();
            
            if (tick <= currentTick)
            {
                messagesOfCurrentTick.add(message);
            }
            else
            {
                break;
            }
        }
        
        // update holding notes
        // simply add all note-ons for the current tick (next tick they'll be holding)
        // also handle note-offs here
        for (const auto &message : messagesOfCurrentTick)
        {
            const int key = midiKeyToArperRangeKey(message.getNoteNumber());
            const double velocity = (double)message.getVelocity() / 128.0;
            
            if (message.isNoteOn())
            {
                holdingNotes[key] = velocity;
            }
            else if (message.isNoteOff())
            {
                holdingNotes[key] = 0.0;
            }
        }
        
        // now fix the targets
        std::fill(targets.begin(), targets.end(), 0.f);
        
        // copy all note-ons of the current tick
        for (const auto &message : messagesOfCurrentTick)
        {
            const int key = midiKeyToArperRangeKey(message.getNoteNumber());
            const double velocity = (double)message.getVelocity() / 128.0;
            
            if (message.isNoteOn())
            {
                targets[key] = velocity;
            }
        }
        
        // train
        this->clNetwork->feed(inputs);
        this->clNetwork->train(0.5, targets);
        
        currentTick++;
    }
    
    // 2. unroll until the silence (or timeout)
    std::fill(inputs.begin(), inputs.end(), 0.f);
    std::fill(targets.begin(), targets.end(), 0.f);
    const int unrollMaxTicks = 24 * 100; // the standard MIDI clock ticks every 24 times every quarter note
    int unrollTicks = 0;
    bool hasOutputs = true;
    while (hasOutputs &&
           unrollTicks++ < unrollMaxTicks)
    {
        const auto feedResult = this->clNetwork->feed(inputs);
        this->clNetwork->train(0.5, targets);
        
        hasOutputs = false;
        for (const double signal : feedResult)
        {
            hasOutputs = hasOutputs | (signal > 0.1);
        }
    }
}
