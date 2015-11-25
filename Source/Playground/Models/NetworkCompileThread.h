/*
  ==============================================================================

    NetworkCompileThread.h
    Created: 20 Nov 2015 3:31:25pm
    Author:  Peter Rudenko

  ==============================================================================
*/

#ifndef NETWORKCOMPILETHREAD_H_INCLUDED
#define NETWORKCOMPILETHREAD_H_INCLUDED

class ProcessingThread : public Thread
{
public:
    
    ProcessingThread() : Thread("ProcessingThread") {}
    
    virtual void run() override
    {
        
    }
    
    //
};


#endif  // NETWORKCOMPILETHREAD_H_INCLUDED
