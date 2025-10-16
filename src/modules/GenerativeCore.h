#pragma once

#include "../core/NexusModule.h"
#include "../core/Placeholders.h" // Includes JsonValue

// Placeholder classes for internal components
class MarkovChain {};
class ControlledRandomWalk {
public:
    float nextMutation() { return 0.0f; }
};
class ParameterAutomation {
public:
    std::vector<void*> getConnectedParameters() { return {}; }
};

/**
 * @brief The brain of the generative system, introducing controlled randomness.
 */
class GenerativeCore : public NexusModule {
private:
    MarkovChain patternGenerator;
    ControlledRandomWalk evolutionEngine;
    ParameterAutomation automationSystem;
    
public:
    /**
     * @brief Applies controlled randomness to connected parameters.
     */
    void evolveParameters();
    
    // NexusModule overrides
    void process(float* buffer, int frames) override;
    void handleInput(NexusConnection* connection) override;
    Json::Value serialize() override;
    void deserialize(Json::Value data) override;
};

