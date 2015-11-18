
#ifndef __JUCE_HEADER_9002020A4DD09B20__
#define __JUCE_HEADER_9002020A4DD09B20__

//[Headers]
//[/Headers]



/**
//[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
//[/Comments]
*/

class MainComponent  : public Component,
                       public ButtonListener
{
public:

    MainComponent ();

    ~MainComponent();

    //[UserMethods]
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);



private:

    //[UserVariables]

    TinyRNN::Network::Ptr network;
    TinyRNN::HardcodedNetwork::Ptr clNetwork;

    //[/UserVariables]

    ScopedPointer<Label> label;
    ScopedPointer<TextButton> loadButton;
    ScopedPointer<TextButton> saveButton;
    ScopedPointer<TextEditor> inputLayerEditor;
    ScopedPointer<Label> label2;
    ScopedPointer<TextEditor> outputLayerEditor;
    ScopedPointer<Label> label3;
    ScopedPointer<TextEditor> numHiddenLayersEditor;
    ScopedPointer<Label> label4;
    ScopedPointer<TextEditor> hiddenLayerEditor;
    ScopedPointer<TextButton> initButton;
    ScopedPointer<TextButton> hardcodeButton;
    ScopedPointer<TextButton> compileButton;
    ScopedPointer<TextButton> trainButton;
    ScopedPointer<TextButton> saveTopoButton;
    ScopedPointer<TextButton> saveStateButton;
    ScopedPointer<TextButton> saveHardcodedTopoButton;
    ScopedPointer<TextButton> saveHardcodedStateButton;
    ScopedPointer<TextButton> saveTrainedHardcodedStateButton;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)

};

//[EndFile]
//[/EndFile]

#endif // __JUCE_HEADER_9002020A4DD09B20__
