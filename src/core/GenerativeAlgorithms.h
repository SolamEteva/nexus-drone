#pragma once

#include <random>
#include <vector>
#include <algorithm>

namespace NexusGenerative {

    /**
     * @brief Controlled Random Walk for parameter evolution.
     * 
     * Applies small, controlled changes to a value over time,
     * allowing for organic and non-repeating parameter movement.
     */
    class ControlledRandomWalk {
    public:
        ControlledRandomWalk(float maxStep = 0.01f, float damping = 0.9f)
            : maxStep(maxStep), damping(damping), currentValue(0.0f), velocity(0.0f) {
            std::random_device rd;
            generator = std::mt19937(rd());
            distribution = std::uniform_real_distribution<float>(-1.0f, 1.0f);
        }

        /**
         * @brief Generates the next mutation value.
         * @return A float representing the change to be applied to a parameter.
         */
        float nextMutation() {
            // Apply a random force
            float force = distribution(generator) * maxStep;

            // Apply damping to velocity
            velocity *= damping;

            // Update velocity with the force
            velocity += force;

            // Clamp velocity to prevent runaway
            velocity = std::clamp(velocity, -maxStep, maxStep);

            // Update value (the mutation is the velocity itself)
            currentValue += velocity;

            // Keep value within a reasonable range (e.g., -1 to 1)
            currentValue = std::clamp(currentValue, -1.0f, 1.0f);

            return velocity;
        }

        void reset() {
            currentValue = 0.0f;
            velocity = 0.0f;
        }

    private:
        float maxStep;
        float damping;
        float currentValue;
        float velocity;

        std::mt19937 generator;
        std::uniform_real_distribution<float> distribution;
    };


    /**
     * @brief Placeholder for a simple Markov Chain pattern generator.
     * 
     * In a real implementation, this would generate sequences of notes or parameter states.
     */
    class MarkovChain {
    public:
        MarkovChain(int states = 4) : currentState(0) {}

        /**
         * @brief Returns the next state in the chain.
         * @return An integer representing the next state index.
         */
        int getNextState() {
            // Placeholder: Simple linear progression for now
            currentState = (currentState + 1) % 4;
            return currentState;
        }

    private:
        int currentState;
    };

} // namespace NexusGenerative

