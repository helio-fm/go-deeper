
#ifndef %%headerGuard%%
#define %%headerGuard%%

//[Headers]
//[/Headers]

%%includeFilesH%%

/**
//[Comments]
//[/Comments]
*/

%%classDeclaration%%
{
public:

    %%className%% (%%constructorParams%%);

    ~%%className%%();

    //[UserMethods]
    //[/UserMethods]

    %%publicMemberDeclarations%%

private:

    //[UserVariables]
    //[/UserVariables]

    %%privateMemberDeclarations%%

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (%%className%%)

};

//[EndFile]
//[/EndFile]

#endif // %%headerGuard%%
