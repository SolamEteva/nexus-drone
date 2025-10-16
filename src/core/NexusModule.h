#pragma once

#include <string>
#include <vector>
#include "Placeholders.h" // Includes NexusConnection, JsonValue, NexusInput, NexusOutput

/**
 * @brief Abstract base class for all modules in the Nexus Drone system.
 * 
 * Provides a standardized interface for audio processing, parameter handling,
 * and state serialization.
 */
class NexusModule {
public:
    // Core DSP processing function
    // buffer: The audio buffer to process (e.g., a JUCE AudioBuffer)
    // frames: The number of samples to process
    virtual void process(float* buffer, int frames) = 0;

    // Handles control voltage (CV) or modulation input from other modules
    virtual void handleInput(NexusConnection* connection) = 0;

    // State serialization for saving patches
    virtual Json::Value serialize() = 0; 

    // State deserialization for loading patches
    virtual void deserialize(Json::Value data) = 0;
    
    virtual ~NexusModule() = default;

protected:
    std::vector<NexusInput*> inputs;
    std::vector<NexusOutput*> outputs;
    std::string moduleType;
    bool bypassed = false;
};

