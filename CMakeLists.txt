# Nexus Drone Synthesizer - CMake Build Configuration

cmake_minimum_required(VERSION 3.15)
project(NexusDrone VERSION 0.1.0)

# Set C++ standard to 17 as is common for modern C++ audio projects
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the source directories
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# --- JUCE Integration Placeholder ---
# In a real setup, this section would handle finding and including the JUCE framework.
# For now, we define the main source files.

# Core Source Files
set(CORE_SOURCES
    ${SOURCE_DIR}/core/NexusModule.cpp
    ${SOURCE_DIR}/core/DSPUtilities.cpp
    ${SOURCE_DIR}/core/GenerativeAlgorithms.cpp
)

# Module Source Files
set(MODULE_SOURCES
    ${SOURCE_DIR}/modules/DualDroneOscillator.cpp
    ${SOURCE_DIR}/modules/GenerativeCore.cpp
    # Add other module files here
)

# Main Plugin Source Files (Placeholder for JUCE's standard structure)
set(PLUGIN_SOURCES
    ${SOURCE_DIR}/PluginProcessor.cpp
    ${SOURCE_DIR}/PluginEditor.cpp
)

# Combine all sources
set(ALL_SOURCES
    ${CORE_SOURCES}
    ${MODULE_SOURCES}
    ${PLUGIN_SOURCES}
)

# Define the target (This will be the plugin/standalone application)
# In a real JUCE project, this would be handled by the Projucer or a more complex
# CMake setup that uses JUCE's CMake API.
add_library(NexusDroneEngine STATIC ${ALL_SOURCES})

# Include directories
target_include_directories(NexusDroneEngine PUBLIC
    ${SOURCE_DIR}
    ${SOURCE_DIR}/core
    ${SOURCE_DIR}/modules
    # Add JUCE include paths here
)

# --- Link Libraries Placeholder ---
# target_link_libraries(NexusDroneEngine PUBLIC JUCE::juce_audio_basics JUCE::juce_gui_basics ...)

