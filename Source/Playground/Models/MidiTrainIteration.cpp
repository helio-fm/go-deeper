/*
  ==============================================================================

    MidiTrainIteration.cpp
    Created: 20 Nov 2015 4:47:54pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "MidiTrainIteration.h"

MidiTrainIteration::MidiTrainIteration(TinyRNN::HardcodedNetwork::Ptr targetNetwork) :
clNetwork(targetNetwork)
{
    // todo asserts for the number of neurons in input and output layers, etc
    jassert(targetNetwork->getContext()->getOutputs().size() == 256);
    
    
    
}

// Process one iteration of training.
void MidiTrainIteration::processWith(const MidiMessageSequence &sortedSequence)
{
    // 1. go through events and train the network
    
    // input:
    // starting chords
    // x[128]
    // holding chords
    // x[128]
    
    // output:
    // probability of every note's on
    // x[128]
    // probability of every note's hold
    // x[128]
    
    const int playingNotesBaseIndex = 0;
    const int holdingNotesBaseIndex = 128;
    
    long long currentTick = (long long)sortedSequence.getStartTime();
    const long long lastTick = (long long)sortedSequence.getEndTime();
    
    int currentEventIndex = 0;
    
    // presuming that we have the lstm like 256 -> 512 -> 512 -> 512 -> 256
    
    // go through every tick
    // write to input exising holding notes
    
    // once we get note on, we add it to the holdingNotes
    // if there are <= 2 note-ons this tick, dont write to input (dont seem to be chord)
    // else write to input as note-ons
    
    TinyRNN::HardcodedTrainingContext::RawData inputs;
    inputs.resize(256);
    
    TinyRNN::HardcodedTrainingContext::RawData targets;
    targets.resize(256);
    
    std::unordered_map<int, double> holdingNotes;
    
    while (currentTick <= lastTick)
    {
        // сначала разбираемся с входными данными
        inputs.clear();
        
        // записываем на вход все звучащие ноты
        for (int i = 0; i < 128; ++i)
        {
            inputs[holdingNotesBaseIndex + i] = holdingNotes[i];
        }
        
        // находим все события для текущего тика
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
        
        // обновляем holding notes
        for (const auto &message : messagesOfCurrentTick)
        {
            const int key = message.getNoteNumber();
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
        
        // записываем на вход все новые ноты, если это аккорд
        const bool seemsToBeChord = (messagesOfCurrentTick.size() > 2);
        if (seemsToBeChord)
        {
            for (const auto &message : messagesOfCurrentTick)
            {
                const int key = message.getNoteNumber();
                const double velocity = (double)message.getVelocity() / 128.0;
                
                if (message.isNoteOn())
                {
                    inputs[playingNotesBaseIndex + key] = velocity;
                }
            }
        }

        // теперь разбираемся с таргетами
        targets.clear();
        
        // записываем туда все звучащие ноты
        for (int i = 0; i < 128; ++i)
        {
            targets[holdingNotesBaseIndex + i] = holdingNotes[i];
        }
        
        // записываем на target все новые ноты
        for (const auto &message : messagesOfCurrentTick)
        {
            const int key = message.getNoteNumber();
            const double velocity = (double)message.getVelocity() / 128.0;
            
            if (message.isNoteOn())
            {
                targets[playingNotesBaseIndex + key] = velocity;
            }
        }
        
        // учим
        this->clNetwork->feed(inputs);
        this->clNetwork->train(0.5, targets);
        
        currentTick++;
    }
    
    // 2. unroll until the silence
    inputs.clear();
    targets.clear();
    bool hasOutputs = true;
    while (hasOutputs)
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


