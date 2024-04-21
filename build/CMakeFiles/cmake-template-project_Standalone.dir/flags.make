# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# compile CXX with /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
CXX_DEFINES = -DCMAKE_BUILD_TYPE=\"Debug\" -DDEBUG=1 -DJUCE_DISPLAY_SPLASH_SCREEN=0 -DJUCE_GLOBAL_MODULE_SETTINGS_INCLUDED=1 -DJUCE_MODULE_AVAILABLE_juce_audio_basics=1 -DJUCE_MODULE_AVAILABLE_juce_audio_devices=1 -DJUCE_MODULE_AVAILABLE_juce_audio_formats=1 -DJUCE_MODULE_AVAILABLE_juce_audio_plugin_client=1 -DJUCE_MODULE_AVAILABLE_juce_audio_processors=1 -DJUCE_MODULE_AVAILABLE_juce_audio_utils=1 -DJUCE_MODULE_AVAILABLE_juce_core=1 -DJUCE_MODULE_AVAILABLE_juce_cryptography=1 -DJUCE_MODULE_AVAILABLE_juce_data_structures=1 -DJUCE_MODULE_AVAILABLE_juce_dsp=1 -DJUCE_MODULE_AVAILABLE_juce_events=1 -DJUCE_MODULE_AVAILABLE_juce_graphics=1 -DJUCE_MODULE_AVAILABLE_juce_gui_basics=1 -DJUCE_MODULE_AVAILABLE_juce_gui_extra=1 -DJUCE_MODULE_AVAILABLE_juce_product_unlocking=1 -DJUCE_PROJECT_NAME=\"cmake-template-project\" -DJUCE_STANDALONE_APPLICATION=JucePlugin_Build_Standalone -DJUCE_TARGET_HAS_BINARY_DATA=1 -DJUCE_USE_CURL=0 -DJUCE_VST3_CAN_REPLACE_VST2=0 -DJUCE_WEB_BROWSER=1 -DJucePlugin_AAXCategory=0 -DJucePlugin_AAXDisableBypass=0 -DJucePlugin_AAXDisableMultiMono=0 -DJucePlugin_AAXIdentifier=com.viator-dsp.cmake-template-project -DJucePlugin_AAXManufacturerCode=JucePlugin_ManufacturerCode -DJucePlugin_AAXProductId=JucePlugin_PluginCode -DJucePlugin_ARACompatibleArchiveIDs=\"\" -DJucePlugin_ARAContentTypes=0 -DJucePlugin_ARADocumentArchiveID=\"com.viator-dsp.cmake-template-project.aradocumentarchive.1\" -DJucePlugin_ARAFactoryID=\"com.viator-dsp.cmake-template-project.arafactory.0.0.1\" -DJucePlugin_ARATransformationFlags=0 -DJucePlugin_AUExportPrefix=cmake_template_projectAU -DJucePlugin_AUExportPrefixQuoted=\"cmake_template_projectAU\" -DJucePlugin_AUMainType="'aufx'" -DJucePlugin_AUManufacturerCode=JucePlugin_ManufacturerCode -DJucePlugin_AUSubType=JucePlugin_PluginCode -DJucePlugin_Build_AAX=0 -DJucePlugin_Build_AU=0 -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_LV2=0 -DJucePlugin_Build_Standalone=1 -DJucePlugin_Build_Unity=0 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_VST=0 -DJucePlugin_CFBundleIdentifier=com.viator-dsp.cmake-template-project -DJucePlugin_Desc=\"cmake-template-project\" -DJucePlugin_EditorRequiresKeyboardFocus=0 -DJucePlugin_Enable_ARA=0 -DJucePlugin_IsMidiEffect=0 -DJucePlugin_IsSynth=0 -DJucePlugin_Manufacturer="\"Viator DSP\"" -DJucePlugin_ManufacturerCode=0x42414245 -DJucePlugin_ManufacturerEmail=\"\" -DJucePlugin_ManufacturerWebsite=\"\" -DJucePlugin_Name=\"cmake-template-project\" -DJucePlugin_PluginCode=0x594f6b54 -DJucePlugin_ProducesMidiOutput=0 -DJucePlugin_VSTCategory=kPlugCategEffect -DJucePlugin_VSTNumMidiInputs=16 -DJucePlugin_VSTNumMidiOutputs=16 -DJucePlugin_VSTUniqueID=JucePlugin_PluginCode -DJucePlugin_Version=0.0.1 -DJucePlugin_VersionCode=0x1 -DJucePlugin_VersionString=\"0.0.1\" -DJucePlugin_Vst3Category=\"Fx\" -DJucePlugin_WantsMidiInput=0 -DPRODUCT_NAME_WITHOUT_VERSION=\"cmake-template-plugin\" -DVERSION=\"0.0.1\" -D_DEBUG=1

CXX_INCLUDES = -I/Volumes/Land00m/GitHub/cmake-template-plugin/build/cmake-template-project_artefacts/JuceLibraryCode -I/Volumes/Land00m/GitHub/cmake-template-plugin/source -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I/Volumes/Land00m/GitHub/cmake-template-plugin/libs/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I/Volumes/Land00m/GitHub/cmake-template-plugin/build/juce_binarydata_Assets/JuceLibraryCode

CXX_FLAGSarm64 = -g -arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk -fPIE -fvisibility=hidden -fvisibility-inlines-hidden   -w -g -O0 -Wall -Wshadow-all -Wshorten-64-to-32 -Wstrict-aliasing -Wuninitialized -Wunused-parameter -Wconversion -Wsign-compare -Wint-conversion -Wconditional-uninitialized -Wconstant-conversion -Wsign-conversion -Wbool-conversion -Wextra-semi -Wunreachable-code -Wcast-align -Wshift-sign-overflow -Wmissing-prototypes -Wnullable-to-nonnull-conversion -Wno-ignored-qualifiers -Wswitch-enum -Wpedantic -Wdeprecated -Wfloat-equal -Wmissing-field-initializers -Wzero-as-null-pointer-constant -Wunused-private-field -Woverloaded-virtual -Wreorder -Winconsistent-missing-destructor-override -std=gnu++17

CXX_FLAGSx86_64 = -g -arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk -fPIE -fvisibility=hidden -fvisibility-inlines-hidden   -w -g -O0 -Wall -Wshadow-all -Wshorten-64-to-32 -Wstrict-aliasing -Wuninitialized -Wunused-parameter -Wconversion -Wsign-compare -Wint-conversion -Wconditional-uninitialized -Wconstant-conversion -Wsign-conversion -Wbool-conversion -Wextra-semi -Wunreachable-code -Wcast-align -Wshift-sign-overflow -Wmissing-prototypes -Wnullable-to-nonnull-conversion -Wno-ignored-qualifiers -Wswitch-enum -Wpedantic -Wdeprecated -Wfloat-equal -Wmissing-field-initializers -Wzero-as-null-pointer-constant -Wunused-private-field -Woverloaded-virtual -Wreorder -Winconsistent-missing-destructor-override -std=gnu++17

CXX_FLAGS = -g -arch arm64 -arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk -fPIE -fvisibility=hidden -fvisibility-inlines-hidden   -w -g -O0 -Wall -Wshadow-all -Wshorten-64-to-32 -Wstrict-aliasing -Wuninitialized -Wunused-parameter -Wconversion -Wsign-compare -Wint-conversion -Wconditional-uninitialized -Wconstant-conversion -Wsign-conversion -Wbool-conversion -Wextra-semi -Wunreachable-code -Wcast-align -Wshift-sign-overflow -Wmissing-prototypes -Wnullable-to-nonnull-conversion -Wno-ignored-qualifiers -Wswitch-enum -Wpedantic -Wdeprecated -Wfloat-equal -Wmissing-field-initializers -Wzero-as-null-pointer-constant -Wunused-private-field -Woverloaded-virtual -Wreorder -Winconsistent-missing-destructor-override -std=gnu++17

