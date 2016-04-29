# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_692442C7=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../Introjucer/JuceLibraryCode -I ../../../ThirdParty/JUCE/modules -I /usr/local/include -I ./../../../ThirdParty/TinyRNN/Source -I ./../../../Source/Playground -I ./../../../Source/Playground/Models -I ./../../../Source/Playground/UI
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  CXXFLAGS += $(CFLAGS) -std=c++11
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt -lOpenCL

  TARGET := GoDeeper
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_692442C7=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../Introjucer/JuceLibraryCode -I ../../../ThirdParty/JUCE/modules -I /usr/local/include -I ./../../../ThirdParty/TinyRNN/Source -I ./../../../Source/Playground -I ./../../../Source/Playground/Models -I ./../../../Source/Playground/UI
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -O3
  CXXFLAGS += $(CFLAGS) -std=c++11
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -fvisibility=hidden -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt -lOpenCL

  TARGET := GoDeeper
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/BatchTextProcessor_541310b6.o \
  $(OBJDIR)/TextTrainIteration_54a850ad.o \
  $(OBJDIR)/BatchMidiProcessor_ec097f42.o \
  $(OBJDIR)/MidiTrainIteration_ea6d19a1.o \
  $(OBJDIR)/JuceXMLSerializer_a62cae5b.o \
  $(OBJDIR)/PugiXMLSerializer_3ab37ee1.o \
  $(OBJDIR)/UnrolledNetwork_87b791f8.o \
  $(OBJDIR)/TrainingPipeline_57d00287.o \
  $(OBJDIR)/LayerConnectionComponent_2721b54f.o \
  $(OBJDIR)/LayerNodeComponent_1b40e0eb.o \
  $(OBJDIR)/MainComponent_ccb1488d.o \
  $(OBJDIR)/GoDeeper_a72bc665.o \
  $(OBJDIR)/pugixml_e97279fa.o \
  $(OBJDIR)/juce_audio_basics_35a2deab.o \
  $(OBJDIR)/juce_audio_devices_2245a2c1.o \
  $(OBJDIR)/juce_audio_formats_d52ca5c0.o \
  $(OBJDIR)/juce_core_98fa4f3c.o \
  $(OBJDIR)/juce_cryptography_380c4e09.o \
  $(OBJDIR)/juce_data_structures_389bc3e2.o \
  $(OBJDIR)/juce_events_47f4b9b6.o \
  $(OBJDIR)/juce_graphics_9c888028.o \
  $(OBJDIR)/juce_gui_basics_2ebc0226.o \
  $(OBJDIR)/juce_gui_extra_57915959.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(RESOURCES)
	@echo Linking GoDeeper
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning GoDeeper
	@$(CLEANCMD)

strip:
	@echo Stripping GoDeeper
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/BatchTextProcessor_541310b6.o: ../../../Source/Playground/Models/BatchTextProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BatchTextProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TextTrainIteration_54a850ad.o: ../../../Source/Playground/Models/TextTrainIteration.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TextTrainIteration.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BatchMidiProcessor_ec097f42.o: ../../../Source/Playground/Models/BatchMidiProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BatchMidiProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiTrainIteration_ea6d19a1.o: ../../../Source/Playground/Models/MidiTrainIteration.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiTrainIteration.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/JuceXMLSerializer_a62cae5b.o: ../../../Source/Playground/Models/JuceXMLSerializer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling JuceXMLSerializer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PugiXMLSerializer_3ab37ee1.o: ../../../Source/Playground/Models/PugiXMLSerializer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PugiXMLSerializer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/UnrolledNetwork_87b791f8.o: ../../../Source/Playground/Models/UnrolledNetwork.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling UnrolledNetwork.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TrainingPipeline_57d00287.o: ../../../Source/Playground/Models/TrainingPipeline.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TrainingPipeline.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/LayerConnectionComponent_2721b54f.o: ../../../Source/Playground/UI/LayerConnectionComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling LayerConnectionComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/LayerNodeComponent_1b40e0eb.o: ../../../Source/Playground/UI/LayerNodeComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling LayerNodeComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MainComponent_ccb1488d.o: ../../../Source/Playground/UI/MainComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MainComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/GoDeeper_a72bc665.o: ../../../Source/Playground/GoDeeper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling GoDeeper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/pugixml_e97279fa.o: ../../../ThirdParty/pugixml/src/pugixml.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling pugixml.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_35a2deab.o: ../../Introjucer/JuceLibraryCode/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_2245a2c1.o: ../../Introjucer/JuceLibraryCode/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_d52ca5c0.o: ../../Introjucer/JuceLibraryCode/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_98fa4f3c.o: ../../Introjucer/JuceLibraryCode/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_cryptography_380c4e09.o: ../../Introjucer/JuceLibraryCode/juce_cryptography.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_cryptography.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_389bc3e2.o: ../../Introjucer/JuceLibraryCode/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_47f4b9b6.o: ../../Introjucer/JuceLibraryCode/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_9c888028.o: ../../Introjucer/JuceLibraryCode/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_2ebc0226.o: ../../Introjucer/JuceLibraryCode/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_57915959.o: ../../Introjucer/JuceLibraryCode/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
