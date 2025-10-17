#pragma once

#include <cmath>
#include <algorithm>

namespace NexusDSP {

    // Define PI for convenience
    constexpr float PI = 3.14159265358979323846f;
    constexpr float TWO_PI = 2.0f * PI;

    /**
     * @brief A simple, band-limited-ish sine wave oscillator.
     * 
     * This is a basic implementation for placeholder purposes.
     * A real JUCE plugin would use more advanced, band-limited oscillators.
     */
    class SimpleOscillator {
    public:
        SimpleOscillator() : sampleRate(44100.0f), phase(0.0f), frequency(440.0f) {}

        void setSampleRate(float rate) { sampleRate = rate; }
        void setFrequency(float freq) { frequency = freq; }

        float getNextSample() {
            const float output = std::sin(phase);
            phase += TWO_PI * frequency / sampleRate;
            if (phase >= TWO_PI) {
                phase -= TWO_PI;
            }
            return output;
        }

    private:
        float sampleRate;
        float phase;
        float frequency;
    };

    /**
     * @brief A simple one-pole low-pass filter.
     */
    class OnePoleFilter {
    public:
        OnePoleFilter() : a1(0.0f), z1(0.0f) {}

        void setCutoff(float cutoffHz, float sampleRate) {
            // Calculate coefficient for a simple one-pole low-pass
            // a1 = exp(-2 * PI * cutoffHz / sampleRate)
            // For simplicity and stability in this placeholder:
            float w0 = TWO_PI * cutoffHz / sampleRate;
            a1 = (2.0f - w0) / (2.0f + w0);
            b0 = w0 / (2.0f + w0);
        }

        float process(float input) {
            z1 = (input * b0) + (z1 * a1);
            return z1;
        }

    private:
        float a1, b0;
        float z1; // Previous output
    };

} // namespace NexusDSP

