# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

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
  $(OBJDIR)/BatchMidiProcessor_ec097f42.o \
  $(OBJDIR)/MidiTrainIteration_ea6d19a1.o \
  $(OBJDIR)/TrainingPipeline_57d00287.o \
  $(OBJDIR)/XMLSerializer_6229ec8.o \
  $(OBJDIR)/LayerConnectionComponent_2721b54f.o \
  $(OBJDIR)/LayerNodeComponent_1b40e0eb.o \
  $(OBJDIR)/MainComponent_ccb1488d.o \
  $(OBJDIR)/Main_782f75fd.o \
  $(OBJDIR)/juce_audio_basics_6432d8fd.o \
  $(OBJDIR)/juce_audio_devices_a88be27b.o \
  $(OBJDIR)/juce_audio_formats_d70d2c1b.o \
  $(OBJDIR)/juce_core_f7efbdf.o \
  $(OBJDIR)/juce_cryptography_65b7dc39.o \
  $(OBJDIR)/juce_data_structures_6c162e5b.o \
  $(OBJDIR)/juce_events_1b6260d3.o \
  $(OBJDIR)/juce_graphics_be749eb7.o \
  $(OBJDIR)/juce_gui_basics_1e8bd2b3.o \
  $(OBJDIR)/juce_gui_extra_171914fb.o \

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

$(OBJDIR)/BatchMidiProcessor_ec097f42.o: ../../../Source/Playground/Models/BatchMidiProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BatchMidiProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiTrainIteration_ea6d19a1.o: ../../../Source/Playground/Models/MidiTrainIteration.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiTrainIteration.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TrainingPipeline_57d00287.o: ../../../Source/Playground/Models/TrainingPipeline.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TrainingPipeline.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/XMLSerializer_6229ec8.o: ../../../Source/Playground/Models/XMLSerializer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling XMLSerializer.cpp"
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

$(OBJDIR)/Main_782f75fd.o: ../../../Source/Playground/Main.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_6432d8fd.o: ../../../ThirdParty/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_a88be27b.o: ../../../ThirdParty/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_d70d2c1b.o: ../../../ThirdParty/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_f7efbdf.o: ../../../ThirdParty/JUCE/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_cryptography_65b7dc39.o: ../../../ThirdParty/JUCE/modules/juce_cryptography/juce_cryptography.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_cryptography.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_6c162e5b.o: ../../../ThirdParty/JUCE/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_1b6260d3.o: ../../../ThirdParty/JUCE/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_be749eb7.o: ../../../ThirdParty/JUCE/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_1e8bd2b3.o: ../../../ThirdParty/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_171914fb.o: ../../../ThirdParty/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
