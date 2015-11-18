
//[Headers]
#include "Precompiled.h"
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs]
#include "XMLSerializer.h"
//[/MiscUserDefs]

MainComponent::MainComponent()
{
    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Input layer:")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredRight);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (loadButton = new TextButton (String::empty));
    loadButton->setButtonText (TRANS("Load as XML"));
    loadButton->addListener (this);

    addAndMakeVisible (saveButton = new TextButton (String::empty));
    saveButton->setButtonText (TRANS("Save as XML"));
    saveButton->addListener (this);

    addAndMakeVisible (inputLayerEditor = new TextEditor (String::empty));
    inputLayerEditor->setMultiLine (false);
    inputLayerEditor->setReturnKeyStartsNewLine (false);
    inputLayerEditor->setReadOnly (false);
    inputLayerEditor->setScrollbarsShown (true);
    inputLayerEditor->setCaretVisible (true);
    inputLayerEditor->setPopupMenuEnabled (true);
    inputLayerEditor->setText (TRANS("33"));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Output layer:")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredRight);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputLayerEditor = new TextEditor (String::empty));
    outputLayerEditor->setMultiLine (false);
    outputLayerEditor->setReturnKeyStartsNewLine (false);
    outputLayerEditor->setReadOnly (false);
    outputLayerEditor->setScrollbarsShown (true);
    outputLayerEditor->setCaretVisible (true);
    outputLayerEditor->setPopupMenuEnabled (true);
    outputLayerEditor->setText (TRANS("33"));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Hidden layers:")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredRight);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::white);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (numHiddenLayersEditor = new TextEditor (String::empty));
    numHiddenLayersEditor->setMultiLine (false);
    numHiddenLayersEditor->setReturnKeyStartsNewLine (false);
    numHiddenLayersEditor->setReadOnly (false);
    numHiddenLayersEditor->setScrollbarsShown (true);
    numHiddenLayersEditor->setCaretVisible (true);
    numHiddenLayersEditor->setPopupMenuEnabled (true);
    numHiddenLayersEditor->setText (TRANS("3"));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Hidden layer:")));
    label4->setFont (Font (15.00f, Font::plain));
    label4->setJustificationType (Justification::centredRight);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colours::white);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (hiddenLayerEditor = new TextEditor (String::empty));
    hiddenLayerEditor->setMultiLine (false);
    hiddenLayerEditor->setReturnKeyStartsNewLine (false);
    hiddenLayerEditor->setReadOnly (false);
    hiddenLayerEditor->setScrollbarsShown (true);
    hiddenLayerEditor->setCaretVisible (true);
    hiddenLayerEditor->setPopupMenuEnabled (true);
    hiddenLayerEditor->setText (TRANS("512"));

    addAndMakeVisible (initButton = new TextButton (String::empty));
    initButton->setButtonText (TRANS("Init"));
    initButton->addListener (this);

    addAndMakeVisible (hardcodeButton = new TextButton (String::empty));
    hardcodeButton->setButtonText (TRANS("Hardcode"));
    hardcodeButton->addListener (this);

    addAndMakeVisible (compileButton = new TextButton (String::empty));
    compileButton->setButtonText (TRANS("Compile"));
    compileButton->addListener (this);

    addAndMakeVisible (trainButton = new TextButton (String::empty));
    trainButton->setButtonText (TRANS("Train"));
    trainButton->addListener (this);

    addAndMakeVisible (saveTopoButton = new TextButton (String::empty));
    saveTopoButton->setButtonText (TRANS("Save topology"));
    saveTopoButton->addListener (this);

    addAndMakeVisible (saveStateButton = new TextButton (String::empty));
    saveStateButton->setButtonText (TRANS("Save state"));
    saveStateButton->addListener (this);

    addAndMakeVisible (saveHardcodedTopoButton = new TextButton (String::empty));
    saveHardcodedTopoButton->setButtonText (TRANS("Save kernels"));
    saveHardcodedTopoButton->addListener (this);

    addAndMakeVisible (saveHardcodedStateButton = new TextButton (String::empty));
    saveHardcodedStateButton->setButtonText (TRANS("Save memory"));
    saveHardcodedStateButton->addListener (this);

    addAndMakeVisible (saveTrainedHardcodedStateButton = new TextButton (String::empty));
    saveTrainedHardcodedStateButton->setButtonText (TRANS("Save memory"));
    saveTrainedHardcodedStateButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor]
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]
    //[/Destructor_pre]

    label = nullptr;
    loadButton = nullptr;
    saveButton = nullptr;
    inputLayerEditor = nullptr;
    label2 = nullptr;
    outputLayerEditor = nullptr;
    label3 = nullptr;
    numHiddenLayersEditor = nullptr;
    label4 = nullptr;
    hiddenLayerEditor = nullptr;
    initButton = nullptr;
    hardcodeButton = nullptr;
    compileButton = nullptr;
    trainButton = nullptr;
    saveTopoButton = nullptr;
    saveStateButton = nullptr;
    saveHardcodedTopoButton = nullptr;
    saveHardcodedStateButton = nullptr;
    saveTrainedHardcodedStateButton = nullptr;


    //[Destructor]
    //[/Destructor]
}

void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff424242));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (16, 16, 112, 24);
    loadButton->setBounds (getWidth() - 18 - 150, 16, 150, 32);
    saveButton->setBounds (getWidth() - 18 - 150, 56, 150, 32);
    inputLayerEditor->setBounds (136, 16, 150, 24);
    label2->setBounds (16, 48, 112, 24);
    outputLayerEditor->setBounds (136, 48, 150, 24);
    label3->setBounds (16, 112, 112, 24);
    numHiddenLayersEditor->setBounds (136, 112, 150, 24);
    label4->setBounds (16, 80, 112, 24);
    hiddenLayerEditor->setBounds (136, 80, 150, 24);
    initButton->setBounds (32, 184, 128, 32);
    hardcodeButton->setBounds (168, 184, 128, 32);
    compileButton->setBounds (304, 184, 128, 32);
    trainButton->setBounds (440, 184, 128, 32);
    saveTopoButton->setBounds (32, 240, 128, 32);
    saveStateButton->setBounds (32, 280, 128, 32);
    saveHardcodedTopoButton->setBounds (168, 240, 128, 32);
    saveHardcodedStateButton->setBounds (168, 280, 128, 32);
    saveTrainedHardcodedStateButton->setBounds (440, 240, 128, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == loadButton)
    {
        //[UserButtonCode_loadButton] -- add your button handler code here..
        //[/UserButtonCode_loadButton]
    }
    else if (buttonThatWasClicked == saveButton)
    {
        //[UserButtonCode_saveButton] -- add your button handler code here..
        //[/UserButtonCode_saveButton]
    }
    else if (buttonThatWasClicked == initButton)
    {
        //[UserButtonCode_initButton] -- add your button handler code here..
        {
            TinyRNN::ScopedTimer timer("Creating a network");

            this->clNetwork = nullptr;

            const int inputLayerSize = this->inputLayerEditor->getText().getIntValue();
            const int outputLayerSize = this->outputLayerEditor->getText().getIntValue();
            const int hiddenLayerSize = this->hiddenLayerEditor->getText().getIntValue();
            const int numHiddenLayers = this->numHiddenLayersEditor->getText().getIntValue();

            std::vector<int> hiddenLayersSizes;
            for (int i = 0; i < numHiddenLayers; ++i)
            {
                hiddenLayersSizes.push_back(hiddenLayerSize);
            }

            this->network = TinyRNN::Network::Prefabs::longShortTermMemory("test", inputLayerSize, hiddenLayersSizes, outputLayerSize);
        }
        //[/UserButtonCode_initButton]
    }
    else if (buttonThatWasClicked == hardcodeButton)
    {
        //[UserButtonCode_hardcodeButton] -- add your button handler code here..
        if (this->network != nullptr)
        {
            TinyRNN::ScopedTimer timer("Hardcoding a network");
            this->clNetwork = this->network->hardcode();
        }
        //[/UserButtonCode_hardcodeButton]
    }
    else if (buttonThatWasClicked == compileButton)
    {
        //[UserButtonCode_compileButton] -- add your button handler code here..
        if (this->clNetwork != nullptr)
        {
            TinyRNN::ScopedTimer timer("Compiling a network");
            this->clNetwork->compile();
        }
        //[/UserButtonCode_compileButton]
    }
    else if (buttonThatWasClicked == trainButton)
    {
        //[UserButtonCode_trainButton] -- add your button handler code here..
        //[/UserButtonCode_trainButton]
    }
    else if (buttonThatWasClicked == saveTopoButton)
    {
        //[UserButtonCode_saveTopoButton] -- add your button handler code here..
        if (this->network != nullptr)
        {
            TinyRNN::ScopedTimer timer("Serializing a network topology");
            XMLSerializer serializer;
            File topoXml = File::getSpecialLocation(File::currentExecutableFile).getSiblingFile("topo.xml");
            topoXml.replaceWithText(serializer.serialize(this->network,
                                                         TinyRNN::Keys::Core::Network));
        }
        //[/UserButtonCode_saveTopoButton]
    }
    else if (buttonThatWasClicked == saveStateButton)
    {
        //[UserButtonCode_saveStateButton] -- add your button handler code here..
        if (this->network != nullptr)
        {
            TinyRNN::ScopedTimer timer("Serializing a network state");
            XMLSerializer serializer;
            File stateXml = File::getSpecialLocation(File::currentExecutableFile).getSiblingFile("state.xml");
            stateXml.replaceWithText(serializer.serialize(this->network->getContext(),
                                                          TinyRNN::Keys::Core::TrainingContext));
        }
        //[/UserButtonCode_saveStateButton]
    }
    else if (buttonThatWasClicked == saveHardcodedTopoButton)
    {
        //[UserButtonCode_saveHardcodedTopoButton] -- add your button handler code here..
        if (this->clNetwork != nullptr)
        {
            TinyRNN::ScopedTimer timer("Serializing a hardcoded network kernels");
            XMLSerializer serializer;
            File kernelsXml = File::getSpecialLocation(File::currentExecutableFile).getSiblingFile("kernels.xml");
            kernelsXml.replaceWithText(serializer.serialize(this->clNetwork,
                                                            TinyRNN::Keys::Hardcoded::Network));
        }
        //[/UserButtonCode_saveHardcodedTopoButton]
    }
    else if (buttonThatWasClicked == saveHardcodedStateButton)
    {
        //[UserButtonCode_saveHardcodedStateButton] -- add your button handler code here..
        if (this->clNetwork != nullptr)
        {
            TinyRNN::ScopedTimer timer("Serializing a hardcoded network memory");
            XMLSerializer serializer;
            File memoryXml = File::getSpecialLocation(File::currentExecutableFile).getSiblingFile("memory.xml");
            memoryXml.replaceWithText(serializer.serialize(this->clNetwork->getContext(),
                                                           TinyRNN::Keys::Hardcoded::TrainingContext));
        }
        //[/UserButtonCode_saveHardcodedStateButton]
    }
    else if (buttonThatWasClicked == saveTrainedHardcodedStateButton)
    {
        //[UserButtonCode_saveTrainedHardcodedStateButton] -- add your button handler code here..
        //[/UserButtonCode_saveTrainedHardcodedStateButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode]
//[/MiscUserCode]

#if 0
/*
BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" template="Template"
                 componentName="" parentClasses="public Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff424242"/>
  <LABEL name="new label" id="70d61404210f74c1" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 16 112 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Input layer:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="" id="ce85187f31567abc" memberName="loadButton" virtualName=""
              explicitFocusOrder="0" pos="18Rr 16 150 32" buttonText="Load as XML"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="b5bcb061a6f968c8" memberName="saveButton" virtualName=""
              explicitFocusOrder="0" pos="18Rr 56 150 32" buttonText="Save as XML"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="" id="7a6a257bfd6e6f" memberName="inputLayerEditor" virtualName=""
              explicitFocusOrder="0" pos="136 16 150 24" initialText="33" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="74650aaa39397010" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="16 48 112 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Output layer:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="" id="3b170838c3d64127" memberName="outputLayerEditor"
              virtualName="" explicitFocusOrder="0" pos="136 48 150 24" initialText="33"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="2a1ffc7d6626fe42" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="16 112 112 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Hidden layers:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="" id="77d23c9380ab04a5" memberName="numHiddenLayersEditor"
              virtualName="" explicitFocusOrder="0" pos="136 112 150 24" initialText="3"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="3f55f35559000dd5" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="16 80 112 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Hidden layer:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="" id="bba0566a86ebe171" memberName="hiddenLayerEditor"
              virtualName="" explicitFocusOrder="0" pos="136 80 150 24" initialText="512"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="" id="e6e439cb427d514b" memberName="initButton" virtualName=""
              explicitFocusOrder="0" pos="32 184 128 32" buttonText="Init"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="a214c20bda41c8a4" memberName="hardcodeButton" virtualName=""
              explicitFocusOrder="0" pos="168 184 128 32" buttonText="Hardcode"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="368d5b30411e3231" memberName="compileButton" virtualName=""
              explicitFocusOrder="0" pos="304 184 128 32" buttonText="Compile"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="b34062a5e3b39bc4" memberName="trainButton" virtualName=""
              explicitFocusOrder="0" pos="440 184 128 32" buttonText="Train"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="6dc2db72cfa3c3de" memberName="saveTopoButton" virtualName=""
              explicitFocusOrder="0" pos="32 240 128 32" buttonText="Save topology"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="369cf9ce2f48f2ef" memberName="saveStateButton" virtualName=""
              explicitFocusOrder="0" pos="32 280 128 32" buttonText="Save state"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="d9aec828207f232f" memberName="saveHardcodedTopoButton"
              virtualName="" explicitFocusOrder="0" pos="168 240 128 32" buttonText="Save kernels"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="fff0e50a61ae26e7" memberName="saveHardcodedStateButton"
              virtualName="" explicitFocusOrder="0" pos="168 280 128 32" buttonText="Save memory"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="1b15837202d122ce" memberName="saveTrainedHardcodedStateButton"
              virtualName="" explicitFocusOrder="0" pos="440 240 128 32" buttonText="Save memory"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif



//[EndFile]
//[/EndFile]
