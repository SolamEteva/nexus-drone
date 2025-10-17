#pragma once

#include "../core/NexusModule.h"
#include "../core/Placeholders.h" // Includes JsonValue

#include "../core/GenerativeAlgorithms.h"
class ParameterAutomation {
public:
    std::vector<void*> getConnectedParameters() { return {}; }
};

/**
 * @brief The brain of the generative system, introducing controlled randomness.
 */
class GenerativeCore : public NexusModule {
private:
    NexusGenerative::MarkovChain patternGenerator;
    NexusGenerative::ControlledRandomWalk evolutionEngine;
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

