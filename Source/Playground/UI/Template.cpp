
//[Headers]
#include "Precompiled.h"
//[/Headers]

%%includeFilesCPP%%

//[MiscUserDefs]
//[/MiscUserDefs]

%%className%%::%%className%%(%%constructorParams%%)
%%initialisers%%{
    %%constructor%%

    //[Constructor]
    //[/Constructor]
}

%%className%%::~%%className%%()
{
    //[Destructor_pre]
    //[/Destructor_pre]

    %%destructor%%

    //[Destructor]
    //[/Destructor]
}

%%methodDefinitions%%

//[MiscUserCode]
//[/MiscUserCode]

#if 0
/*
BEGIN_JUCER_METADATA

%%metadata%%
END_JUCER_METADATA
*/
#endif

%%staticMemberDefinitions%%

//[EndFile]
//[/EndFile]
