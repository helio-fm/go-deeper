
//[Headers]
//[/Headers]

#include "LayerConnectionComponent.h"


//[MiscUserDefs]
//[/MiscUserDefs]

LayerConnectionComponent::LayerConnectionComponent()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor]
    //[/Constructor]
}

LayerConnectionComponent::~LayerConnectionComponent()
{
    //[Destructor_pre]
    //[/Destructor_pre]



    //[Destructor]
    //[/Destructor]
}

void LayerConnectionComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LayerConnectionComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode]
//[/MiscUserCode]

#if 0
/*
BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LayerConnectionComponent"
                 template="Template" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif



//[EndFile]
//[/EndFile]
