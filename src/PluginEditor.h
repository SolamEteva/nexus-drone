#pragma once

// Forward declarations for JUCE classes to allow this header to compile conceptually
namespace juce
{
    class AudioProcessorEditor;
    class AudioProcessor;
    class Slider;
    class Label;
}

// Forward declaration of the Processor class
class NexusDroneAudioProcessor;

/**
 * @brief The AudioProcessorEditor class for the Nexus Drone synthesizer.
 * 
 * This class handles the graphical user interface.
 */
class NexusDroneAudioProcessorEditor final // : public juce::AudioProcessorEditor
{
public:
    //==============================================================================
    NexusDroneAudioProcessorEditor (NexusDroneAudioProcessor&);
    ~NexusDroneAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is used to access the processor object that created this editor.
    NexusDroneAudioProcessor& processorRef;

    // GUI components (placeholders)
    // juce::Slider morphSlider;
    // juce::Label morphLabel;

    // JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NexusDroneAudioProcessorEditor)
};

