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

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "TRAINING_MODE=1" -D "JUCER_LINUX_MAKE_692442C7=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../Introjucer/JuceLibraryCode -I ../../../ThirdParty/JUCE/modules -I /usr/local/include -I ./../../../ThirdParty/TinyRNN/Source -I ./../../../Source/Playground -I ./../../../Source/Playground/Models -I ./../../../Source/Playground/UI
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

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "TRAINING_MODE=1" -D "JUCER_LINUX_MAKE_692442C7=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../Introjucer/JuceLibraryCode -I ../../../ThirdParty/JUCE/modules -I /usr/local/include -I ./../../../ThirdParty/TinyRNN/Source -I ./../../../Source/Playground -I ./../../../Source/Playground/Models -I ./../../../Source/Playground/UI
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
  $(OBJDIR)/GoDeeper_a33721d2.o \
  $(OBJDIR)/feed_0_ca9ab160.o \
  $(OBJDIR)/feed_1_ca9ab521.o \
  $(OBJDIR)/feed_2_ca9ab8e2.o \
  $(OBJDIR)/feed_3_ca9abca3.o \
  $(OBJDIR)/feed_4_ca9ac064.o \
  $(OBJDIR)/feed_5_ca9ac425.o \
  $(OBJDIR)/feed_6_ca9ac7e6.o \
  $(OBJDIR)/feed_7_ca9acba7.o \
  $(OBJDIR)/feed_8_ca9acf68.o \
  $(OBJDIR)/feed_9_ca9ad329.o \
  $(OBJDIR)/feed_10_88bbf079.o \
  $(OBJDIR)/feed_11_88bbf43a.o \
  $(OBJDIR)/feed_12_88bbf7fb.o \
  $(OBJDIR)/feed_13_88bbfbbc.o \
  $(OBJDIR)/feed_14_88bbff7d.o \
  $(OBJDIR)/feed_15_88bc033e.o \
  $(OBJDIR)/feed_16_88bc06ff.o \
  $(OBJDIR)/feed_17_88bc0ac0.o \
  $(OBJDIR)/feed_18_88bc0e81.o \
  $(OBJDIR)/feed_19_88bc1242.o \
  $(OBJDIR)/feed_20_88bc64d8.o \
  $(OBJDIR)/feed_21_88bc6899.o \
  $(OBJDIR)/feed_22_88bc6c5a.o \
  $(OBJDIR)/feed_23_88bc701b.o \
  $(OBJDIR)/feed_24_88bc73dc.o \
  $(OBJDIR)/feed_25_88bc779d.o \
  $(OBJDIR)/feed_26_88bc7b5e.o \
  $(OBJDIR)/feed_27_88bc7f1f.o \
  $(OBJDIR)/feed_28_88bc82e0.o \
  $(OBJDIR)/feed_29_88bc86a1.o \
  $(OBJDIR)/feed_30_88bcd937.o \
  $(OBJDIR)/feed_31_88bcdcf8.o \
  $(OBJDIR)/feed_32_88bce0b9.o \
  $(OBJDIR)/feed_33_88bce47a.o \
  $(OBJDIR)/feed_34_88bce83b.o \
  $(OBJDIR)/feed_35_88bcebfc.o \
  $(OBJDIR)/feed_36_88bcefbd.o \
  $(OBJDIR)/feed_37_88bcf37e.o \
  $(OBJDIR)/feed_38_88bcf73f.o \
  $(OBJDIR)/feed_39_88bcfb00.o \
  $(OBJDIR)/feed_40_88bd4d96.o \
  $(OBJDIR)/feed_41_88bd5157.o \
  $(OBJDIR)/feed_42_88bd5518.o \
  $(OBJDIR)/feed_43_88bd58d9.o \
  $(OBJDIR)/feed_44_88bd5c9a.o \
  $(OBJDIR)/feed_45_88bd605b.o \
  $(OBJDIR)/feed_46_88bd641c.o \
  $(OBJDIR)/feed_47_88bd67dd.o \
  $(OBJDIR)/feed_48_88bd6b9e.o \
  $(OBJDIR)/feed_49_88bd6f5f.o \
  $(OBJDIR)/feed_50_88bdc1f5.o \
  $(OBJDIR)/feed_51_88bdc5b6.o \
  $(OBJDIR)/feed_52_88bdc977.o \
  $(OBJDIR)/feed_53_88bdcd38.o \
  $(OBJDIR)/feed_54_88bdd0f9.o \
  $(OBJDIR)/feed_55_88bdd4ba.o \
  $(OBJDIR)/feed_56_88bdd87b.o \
  $(OBJDIR)/feed_57_88bddc3c.o \
  $(OBJDIR)/feed_58_88bddffd.o \
  $(OBJDIR)/feed_59_88bde3be.o \
  $(OBJDIR)/feed_60_88be3654.o \
  $(OBJDIR)/feed_61_88be3a15.o \
  $(OBJDIR)/feed_62_88be3dd6.o \
  $(OBJDIR)/feed_63_88be4197.o \
  $(OBJDIR)/feed_64_88be4558.o \
  $(OBJDIR)/feed_65_88be4919.o \
  $(OBJDIR)/feed_66_88be4cda.o \
  $(OBJDIR)/feed_67_88be509b.o \
  $(OBJDIR)/feed_68_88be545c.o \
  $(OBJDIR)/feed_69_88be581d.o \
  $(OBJDIR)/train_0_20c0e192.o \
  $(OBJDIR)/train_1_20c0e553.o \
  $(OBJDIR)/train_2_20c0e914.o \
  $(OBJDIR)/train_3_20c0ecd5.o \
  $(OBJDIR)/train_4_20c0f096.o \
  $(OBJDIR)/train_5_20c0f457.o \
  $(OBJDIR)/train_6_20c0f818.o \
  $(OBJDIR)/train_7_20c0fbd9.o \
  $(OBJDIR)/train_8_20c0ff9a.o \
  $(OBJDIR)/train_9_20c1035b.o \
  $(OBJDIR)/train_10_f75bc687.o \
  $(OBJDIR)/train_11_f75bca48.o \
  $(OBJDIR)/train_12_f75bce09.o \
  $(OBJDIR)/train_13_f75bd1ca.o \
  $(OBJDIR)/train_14_f75bd58b.o \
  $(OBJDIR)/train_15_f75bd94c.o \
  $(OBJDIR)/train_16_f75bdd0d.o \
  $(OBJDIR)/train_17_f75be0ce.o \
  $(OBJDIR)/train_18_f75be48f.o \
  $(OBJDIR)/train_19_f75be850.o \
  $(OBJDIR)/train_20_f75c3ae6.o \
  $(OBJDIR)/train_21_f75c3ea7.o \
  $(OBJDIR)/train_22_f75c4268.o \
  $(OBJDIR)/train_23_f75c4629.o \
  $(OBJDIR)/train_24_f75c49ea.o \
  $(OBJDIR)/train_25_f75c4dab.o \
  $(OBJDIR)/train_26_f75c516c.o \
  $(OBJDIR)/train_27_f75c552d.o \
  $(OBJDIR)/train_28_f75c58ee.o \
  $(OBJDIR)/train_29_f75c5caf.o \
  $(OBJDIR)/train_30_f75caf45.o \
  $(OBJDIR)/train_31_f75cb306.o \
  $(OBJDIR)/train_32_f75cb6c7.o \
  $(OBJDIR)/train_33_f75cba88.o \
  $(OBJDIR)/train_34_f75cbe49.o \
  $(OBJDIR)/train_35_f75cc20a.o \
  $(OBJDIR)/train_36_f75cc5cb.o \
  $(OBJDIR)/train_37_f75cc98c.o \
  $(OBJDIR)/train_38_f75ccd4d.o \
  $(OBJDIR)/train_39_f75cd10e.o \
  $(OBJDIR)/train_40_f75d23a4.o \
  $(OBJDIR)/train_41_f75d2765.o \
  $(OBJDIR)/train_42_f75d2b26.o \
  $(OBJDIR)/train_43_f75d2ee7.o \
  $(OBJDIR)/train_44_f75d32a8.o \
  $(OBJDIR)/train_45_f75d3669.o \
  $(OBJDIR)/train_46_f75d3a2a.o \
  $(OBJDIR)/train_47_f75d3deb.o \
  $(OBJDIR)/train_48_f75d41ac.o \
  $(OBJDIR)/train_49_f75d456d.o \
  $(OBJDIR)/train_50_f75d9803.o \
  $(OBJDIR)/train_51_f75d9bc4.o \
  $(OBJDIR)/train_52_f75d9f85.o \
  $(OBJDIR)/train_53_f75da346.o \
  $(OBJDIR)/train_54_f75da707.o \
  $(OBJDIR)/train_55_f75daac8.o \
  $(OBJDIR)/train_56_f75dae89.o \
  $(OBJDIR)/train_57_f75db24a.o \
  $(OBJDIR)/train_58_f75db60b.o \
  $(OBJDIR)/train_59_f75db9cc.o \
  $(OBJDIR)/train_60_f75e0c62.o \
  $(OBJDIR)/train_61_f75e1023.o \
  $(OBJDIR)/train_62_f75e13e4.o \
  $(OBJDIR)/train_63_f75e17a5.o \
  $(OBJDIR)/train_64_f75e1b66.o \
  $(OBJDIR)/train_65_f75e1f27.o \
  $(OBJDIR)/train_66_f75e22e8.o \
  $(OBJDIR)/train_67_f75e26a9.o \
  $(OBJDIR)/train_68_f75e2a6a.o \
  $(OBJDIR)/train_69_f75e2e2b.o \
  $(OBJDIR)/train_70_f75e80c1.o \
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

$(OBJDIR)/GoDeeper_a33721d2.o: ../../../Resources/Hardcoded/GoDeeper.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling GoDeeper.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_0_ca9ab160.o: ../../../Resources/Hardcoded/feed_0.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_0.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_1_ca9ab521.o: ../../../Resources/Hardcoded/feed_1.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_1.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_2_ca9ab8e2.o: ../../../Resources/Hardcoded/feed_2.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_2.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_3_ca9abca3.o: ../../../Resources/Hardcoded/feed_3.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_3.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_4_ca9ac064.o: ../../../Resources/Hardcoded/feed_4.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_4.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_5_ca9ac425.o: ../../../Resources/Hardcoded/feed_5.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_5.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_6_ca9ac7e6.o: ../../../Resources/Hardcoded/feed_6.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_6.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_7_ca9acba7.o: ../../../Resources/Hardcoded/feed_7.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_7.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_8_ca9acf68.o: ../../../Resources/Hardcoded/feed_8.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_8.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_9_ca9ad329.o: ../../../Resources/Hardcoded/feed_9.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_9.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_10_88bbf079.o: ../../../Resources/Hardcoded/feed_10.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_10.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_11_88bbf43a.o: ../../../Resources/Hardcoded/feed_11.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_11.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_12_88bbf7fb.o: ../../../Resources/Hardcoded/feed_12.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_12.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_13_88bbfbbc.o: ../../../Resources/Hardcoded/feed_13.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_13.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_14_88bbff7d.o: ../../../Resources/Hardcoded/feed_14.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_14.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_15_88bc033e.o: ../../../Resources/Hardcoded/feed_15.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_15.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_16_88bc06ff.o: ../../../Resources/Hardcoded/feed_16.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_16.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_17_88bc0ac0.o: ../../../Resources/Hardcoded/feed_17.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_17.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_18_88bc0e81.o: ../../../Resources/Hardcoded/feed_18.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_18.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_19_88bc1242.o: ../../../Resources/Hardcoded/feed_19.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_19.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_20_88bc64d8.o: ../../../Resources/Hardcoded/feed_20.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_20.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_21_88bc6899.o: ../../../Resources/Hardcoded/feed_21.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_21.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_22_88bc6c5a.o: ../../../Resources/Hardcoded/feed_22.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_22.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_23_88bc701b.o: ../../../Resources/Hardcoded/feed_23.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_23.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_24_88bc73dc.o: ../../../Resources/Hardcoded/feed_24.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_24.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_25_88bc779d.o: ../../../Resources/Hardcoded/feed_25.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_25.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_26_88bc7b5e.o: ../../../Resources/Hardcoded/feed_26.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_26.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_27_88bc7f1f.o: ../../../Resources/Hardcoded/feed_27.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_27.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_28_88bc82e0.o: ../../../Resources/Hardcoded/feed_28.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_28.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_29_88bc86a1.o: ../../../Resources/Hardcoded/feed_29.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_29.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_30_88bcd937.o: ../../../Resources/Hardcoded/feed_30.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_30.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_31_88bcdcf8.o: ../../../Resources/Hardcoded/feed_31.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_31.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_32_88bce0b9.o: ../../../Resources/Hardcoded/feed_32.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_32.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_33_88bce47a.o: ../../../Resources/Hardcoded/feed_33.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_33.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_34_88bce83b.o: ../../../Resources/Hardcoded/feed_34.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_34.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_35_88bcebfc.o: ../../../Resources/Hardcoded/feed_35.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_35.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_36_88bcefbd.o: ../../../Resources/Hardcoded/feed_36.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_36.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_37_88bcf37e.o: ../../../Resources/Hardcoded/feed_37.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_37.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_38_88bcf73f.o: ../../../Resources/Hardcoded/feed_38.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_38.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_39_88bcfb00.o: ../../../Resources/Hardcoded/feed_39.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_39.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_40_88bd4d96.o: ../../../Resources/Hardcoded/feed_40.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_40.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_41_88bd5157.o: ../../../Resources/Hardcoded/feed_41.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_41.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_42_88bd5518.o: ../../../Resources/Hardcoded/feed_42.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_42.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_43_88bd58d9.o: ../../../Resources/Hardcoded/feed_43.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_43.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_44_88bd5c9a.o: ../../../Resources/Hardcoded/feed_44.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_44.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_45_88bd605b.o: ../../../Resources/Hardcoded/feed_45.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_45.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_46_88bd641c.o: ../../../Resources/Hardcoded/feed_46.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_46.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_47_88bd67dd.o: ../../../Resources/Hardcoded/feed_47.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_47.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_48_88bd6b9e.o: ../../../Resources/Hardcoded/feed_48.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_48.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_49_88bd6f5f.o: ../../../Resources/Hardcoded/feed_49.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_49.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_50_88bdc1f5.o: ../../../Resources/Hardcoded/feed_50.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_50.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_51_88bdc5b6.o: ../../../Resources/Hardcoded/feed_51.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_51.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_52_88bdc977.o: ../../../Resources/Hardcoded/feed_52.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_52.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_53_88bdcd38.o: ../../../Resources/Hardcoded/feed_53.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_53.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_54_88bdd0f9.o: ../../../Resources/Hardcoded/feed_54.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_54.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_55_88bdd4ba.o: ../../../Resources/Hardcoded/feed_55.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_55.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_56_88bdd87b.o: ../../../Resources/Hardcoded/feed_56.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_56.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_57_88bddc3c.o: ../../../Resources/Hardcoded/feed_57.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_57.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_58_88bddffd.o: ../../../Resources/Hardcoded/feed_58.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_58.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_59_88bde3be.o: ../../../Resources/Hardcoded/feed_59.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_59.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_60_88be3654.o: ../../../Resources/Hardcoded/feed_60.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_60.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_61_88be3a15.o: ../../../Resources/Hardcoded/feed_61.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_61.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_62_88be3dd6.o: ../../../Resources/Hardcoded/feed_62.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_62.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_63_88be4197.o: ../../../Resources/Hardcoded/feed_63.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_63.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_64_88be4558.o: ../../../Resources/Hardcoded/feed_64.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_64.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_65_88be4919.o: ../../../Resources/Hardcoded/feed_65.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_65.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_66_88be4cda.o: ../../../Resources/Hardcoded/feed_66.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_66.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_67_88be509b.o: ../../../Resources/Hardcoded/feed_67.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_67.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_68_88be545c.o: ../../../Resources/Hardcoded/feed_68.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_68.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/feed_69_88be581d.o: ../../../Resources/Hardcoded/feed_69.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling feed_69.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_0_20c0e192.o: ../../../Resources/Hardcoded/train_0.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_0.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_1_20c0e553.o: ../../../Resources/Hardcoded/train_1.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_1.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_2_20c0e914.o: ../../../Resources/Hardcoded/train_2.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_2.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_3_20c0ecd5.o: ../../../Resources/Hardcoded/train_3.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_3.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_4_20c0f096.o: ../../../Resources/Hardcoded/train_4.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_4.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_5_20c0f457.o: ../../../Resources/Hardcoded/train_5.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_5.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_6_20c0f818.o: ../../../Resources/Hardcoded/train_6.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_6.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_7_20c0fbd9.o: ../../../Resources/Hardcoded/train_7.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_7.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_8_20c0ff9a.o: ../../../Resources/Hardcoded/train_8.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_8.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_9_20c1035b.o: ../../../Resources/Hardcoded/train_9.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_9.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_10_f75bc687.o: ../../../Resources/Hardcoded/train_10.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_10.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_11_f75bca48.o: ../../../Resources/Hardcoded/train_11.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_11.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_12_f75bce09.o: ../../../Resources/Hardcoded/train_12.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_12.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_13_f75bd1ca.o: ../../../Resources/Hardcoded/train_13.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_13.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_14_f75bd58b.o: ../../../Resources/Hardcoded/train_14.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_14.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_15_f75bd94c.o: ../../../Resources/Hardcoded/train_15.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_15.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_16_f75bdd0d.o: ../../../Resources/Hardcoded/train_16.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_16.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_17_f75be0ce.o: ../../../Resources/Hardcoded/train_17.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_17.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_18_f75be48f.o: ../../../Resources/Hardcoded/train_18.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_18.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_19_f75be850.o: ../../../Resources/Hardcoded/train_19.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_19.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_20_f75c3ae6.o: ../../../Resources/Hardcoded/train_20.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_20.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_21_f75c3ea7.o: ../../../Resources/Hardcoded/train_21.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_21.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_22_f75c4268.o: ../../../Resources/Hardcoded/train_22.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_22.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_23_f75c4629.o: ../../../Resources/Hardcoded/train_23.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_23.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_24_f75c49ea.o: ../../../Resources/Hardcoded/train_24.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_24.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_25_f75c4dab.o: ../../../Resources/Hardcoded/train_25.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_25.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_26_f75c516c.o: ../../../Resources/Hardcoded/train_26.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_26.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_27_f75c552d.o: ../../../Resources/Hardcoded/train_27.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_27.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_28_f75c58ee.o: ../../../Resources/Hardcoded/train_28.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_28.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_29_f75c5caf.o: ../../../Resources/Hardcoded/train_29.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_29.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_30_f75caf45.o: ../../../Resources/Hardcoded/train_30.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_30.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_31_f75cb306.o: ../../../Resources/Hardcoded/train_31.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_31.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_32_f75cb6c7.o: ../../../Resources/Hardcoded/train_32.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_32.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_33_f75cba88.o: ../../../Resources/Hardcoded/train_33.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_33.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_34_f75cbe49.o: ../../../Resources/Hardcoded/train_34.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_34.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_35_f75cc20a.o: ../../../Resources/Hardcoded/train_35.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_35.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_36_f75cc5cb.o: ../../../Resources/Hardcoded/train_36.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_36.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_37_f75cc98c.o: ../../../Resources/Hardcoded/train_37.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_37.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_38_f75ccd4d.o: ../../../Resources/Hardcoded/train_38.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_38.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_39_f75cd10e.o: ../../../Resources/Hardcoded/train_39.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_39.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_40_f75d23a4.o: ../../../Resources/Hardcoded/train_40.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_40.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_41_f75d2765.o: ../../../Resources/Hardcoded/train_41.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_41.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_42_f75d2b26.o: ../../../Resources/Hardcoded/train_42.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_42.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_43_f75d2ee7.o: ../../../Resources/Hardcoded/train_43.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_43.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_44_f75d32a8.o: ../../../Resources/Hardcoded/train_44.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_44.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_45_f75d3669.o: ../../../Resources/Hardcoded/train_45.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_45.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_46_f75d3a2a.o: ../../../Resources/Hardcoded/train_46.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_46.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_47_f75d3deb.o: ../../../Resources/Hardcoded/train_47.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_47.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_48_f75d41ac.o: ../../../Resources/Hardcoded/train_48.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_48.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_49_f75d456d.o: ../../../Resources/Hardcoded/train_49.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_49.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_50_f75d9803.o: ../../../Resources/Hardcoded/train_50.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_50.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_51_f75d9bc4.o: ../../../Resources/Hardcoded/train_51.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_51.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_52_f75d9f85.o: ../../../Resources/Hardcoded/train_52.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_52.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_53_f75da346.o: ../../../Resources/Hardcoded/train_53.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_53.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_54_f75da707.o: ../../../Resources/Hardcoded/train_54.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_54.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_55_f75daac8.o: ../../../Resources/Hardcoded/train_55.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_55.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_56_f75dae89.o: ../../../Resources/Hardcoded/train_56.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_56.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_57_f75db24a.o: ../../../Resources/Hardcoded/train_57.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_57.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_58_f75db60b.o: ../../../Resources/Hardcoded/train_58.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_58.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_59_f75db9cc.o: ../../../Resources/Hardcoded/train_59.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_59.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_60_f75e0c62.o: ../../../Resources/Hardcoded/train_60.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_60.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_61_f75e1023.o: ../../../Resources/Hardcoded/train_61.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_61.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_62_f75e13e4.o: ../../../Resources/Hardcoded/train_62.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_62.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_63_f75e17a5.o: ../../../Resources/Hardcoded/train_63.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_63.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_64_f75e1b66.o: ../../../Resources/Hardcoded/train_64.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_64.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_65_f75e1f27.o: ../../../Resources/Hardcoded/train_65.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_65.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_66_f75e22e8.o: ../../../Resources/Hardcoded/train_66.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_66.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_67_f75e26a9.o: ../../../Resources/Hardcoded/train_67.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_67.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_68_f75e2a6a.o: ../../../Resources/Hardcoded/train_68.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_68.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_69_f75e2e2b.o: ../../../Resources/Hardcoded/train_69.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_69.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/train_70_f75e80c1.o: ../../../Resources/Hardcoded/train_70.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling train_70.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

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
