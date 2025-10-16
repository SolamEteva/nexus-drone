# Nexus Drone: Generative Aural Synthesizer

A modular, open-source VST/AU/CLAP plugin built with the **JUCE Framework** for generating heavy, evolving sci-fi soundscapes and ambient textures.

## 🚀 Core Features

*   **Dual Drone Voice Engine:** Advanced sound source featuring morphing oscillators, cross-modulation, and analog-modeled sub-oscillators for complex, evolving timbres.
*   **Generative Core:** A unique module that uses **Markov Chains** and **Controlled Random Walk** algorithms to introduce controlled, organic evolution to the synthesizer's parameters over time.
*   **Modular Architecture:** Based on the `NexusModule` interface, allowing for flexible patching, future expansion, and community-driven module development.
*   **Microtonal Tuning:** Support for loading custom tuning systems via `.scala` files, enabling alien and non-standard harmonies.

## 🛠️ Technology Stack

| Component | Technology | Purpose |
| :--- | :--- | :--- |
| **Core** | C++17 | High-performance, low-latency DSP. |
| **Framework** | JUCE | Cross-platform plugin hosting (VST3, AU, CLAP) and GUI development. |
| **Build System** | CMake | Project configuration and dependency management. |
| **GUI** | OpenGL / JUCE Graphics | Fluid, real-time visualizations (scope, spectrum, modulation). |

## ⚙️ Getting Started (Building from Source)

This project requires the JUCE framework to be installed and configured on your system.

### Prerequisites

1.  **JUCE Framework:** Download and install the latest version of the JUCE library and the Projucer application.
2.  **C++ Compiler:** A modern C++ compiler (e.g., GCC, Clang, Visual Studio) supporting C++17.
3.  **CMake:** Version 3.15 or newer.

### Build Instructions

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/YourOrg/nexus-drone.git
    cd nexus-drone
    ```

2.  **Configure Build:**
    The provided `CMakeLists.txt` is a starting point. In a standard JUCE project, you would typically use the Projucer to generate the project files, or use JUCE's CMake API. For this initial setup, we assume a standard CMake flow:
    ```bash
    # Create build directory
    mkdir build
    cd build
    
    # Configure the project (you may need to set JUCE_ROOT_PATH)
    cmake ..
    
    # Build the plugin
    cmake --build . --config Release
    ```

3.  **Installation:** The resulting VST3, AU, or CLAP file will be located in the build directory, ready to be moved to your DAW's plugin folder.

## 🤝 Contributing

We welcome contributions from the community! Please see the `CONTRIBUTING.md` file for detailed guidelines on how to submit code, develop new modules, and report issues.

---
*Created by Manus AI and the Nexus Drone Community.*
