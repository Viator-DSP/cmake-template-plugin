cmake_minimum_required(VERSION 3.23.1)

project(cmake-template-project VERSION 0.0.1)

# Project configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.13" CACHE STRING "Minimum OS X deployment target")
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")

# General setup
set(PROJECT_NAME "cmake-template-project")
set(CURRENT_VERSION "0.0.1")
set(PRODUCT_NAME "cmake-template-project")
set(COMPANY_NAME "Viator DSP")
set(BUNDLE_ID "com.viator-dsp.cmake-template-project")
set(FORMATS Standalone AU VST3)

# Disable all warnings
add_definitions(-w)

# Append custom module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-include/sudara-cmake")

# JUCE and modules
include(JUCEDefaults)
add_subdirectory(libs/JUCE)

# External libraries
#add_subdirectory(externals)

# Test subdirectory
add_subdirectory(tests)

# Define the plugin
juce_add_plugin("${PROJECT_NAME}"
        COMPANY_NAME "${COMPANY_NAME}"
        BUNDLE_ID "${BUNDLE_ID}"
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_MANUFACTURER_CODE BABE
        PLUGIN_CODE YOkT
        FORMATS ${FORMATS}
        PRODUCT_NAME "${PRODUCT_NAME}"
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        IS_SYNTH FALSE
)

add_compile_definitions(JUCE_PROJECT_NAME="${PROJECT_NAME}")

# Define SharedCode as an INTERFACE library
add_library(SharedCode INTERFACE
        source/gui/panels/Header.h
        source/gui/lookandfeel/Colors.h
        source/gui/lookandfeel/Gradient.h
        source/gui/lookandfeel/MenuLAF.h
        source/gui/components/PresetBrowser.h
        source/gui/panels/NavBar.h
        source/gui/panels/ExtrasPage.h)

# Set compile features for SharedCode
target_compile_features(SharedCode INTERFACE cxx_std_20)

# Include directories and compile definitions for SharedCode
target_include_directories(SharedCode INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/source"
        "${CMAKE_CURRENT_SOURCE_DIR}/libs/JUCE/modules"
)

include(Assets)

set(CMAKE_BUILD_TYPE Debug)

target_compile_definitions(SharedCode INTERFACE
        JUCE_WEB_BROWSER=1
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        CMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}"
        VERSION="${CURRENT_VERSION}"
        JUCE_DISPLAY_SPLASH_SCREEN=0
        PRODUCT_NAME_WITHOUT_VERSION="cmake-template-plugin"
)

# Add sources to the main project
file(GLOB_RECURSE SourceFiles CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/source/*.h"
)

# Sources to main project
target_sources("${PROJECT_NAME}" PRIVATE ${SourceFiles})

# Link libraries to main project
target_link_libraries("${PROJECT_NAME}" PRIVATE
        SharedCode
        Assets
        juce::juce_dsp
        juce::juce_audio_utils
        juce::juce_product_unlocking
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
        
)

# Ensure the main project knows where its sources are
target_include_directories("${PROJECT_NAME}" PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/source"
)
