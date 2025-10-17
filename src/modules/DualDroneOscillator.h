#pragma once

#include "../core/NexusModule.h"
#include "../core/Placeholders.h" // Includes JsonValue
#include "../core/DSPUtilities.h"

// Placeholder classes for internal components
class MorphingOscillator : public NexusDSP::SimpleOscillator {};
class CrossModulationMatrix {};
class AnalogModeledSubOsc : public NexusDSP::SimpleOscillator {};
class WaveformMorpher {
public:
    void interpolate(MorphingOscillator& osc1, MorphingOscillator& osc2, float position) {
        // Placeholder: Actual interpolation logic goes here
    }
};

/**
 * @brief The primary sound source, designed for complex, evolving textures.
 */
class DualDroneOscillator : public NexusModule {
private:
    MorphingOscillator osc1, osc2;
    CrossModulationMatrix modMatrix;
    AnalogModeledSubOsc sub1, sub2;
    WaveformMorpher morphEngine;
    
public:
    void setMorphPosition(float position);
    
    // NexusModule overrides
    void process(float* buffer, int frames) override;
    void handleInput(NexusConnection* connection) override;
    Json::Value serialize() override;
    void deserialize(Json::Value data) override;
};

