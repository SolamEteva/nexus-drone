# Contributing to Nexus Drone

Thank you for your interest in contributing to the Nexus Drone project! We are building a powerful, open-source synthesizer for generative sci-fi soundscapes, and your help is invaluable.

## 💡 How to Contribute

There are many ways to contribute, not just by writing code:

1.  **Code Contributions:** Implement new features, fix bugs, or develop new `NexusModule` components.
2.  **Sound Design:** Create and share new patches/presets for the synthesizer.
3.  **Documentation:** Improve the README, technical documentation, or user manual.
4.  **Testing & Reporting:** Find and report bugs, and help verify fixes.

## 💻 Code Contribution Workflow

1.  **Fork the Repository** on GitHub.
2.  **Clone your Fork** locally:
    ```bash
    git clone https://github.com/YourUsername/nexus-drone.git
    cd nexus-drone
    ```
3.  **Create a New Branch** for your feature or fix:
    ```bash
    git checkout -b feature/my-new-module
    # or
    git checkout -b fix/bug-in-oscillator
    ```
4.  **Make Your Changes:**
    *   Ensure your code adheres to the existing style and C++17 standard.
    *   **Focus on the `NexusModule` interface** for new components.
    *   Write clear, concise commit messages.
5.  **Push to your Fork:**
    ```bash
    git push origin feature/my-new-module
    ```
6.  **Open a Pull Request (PR):**
    *   Submit a Pull Request from your branch to the main repository's `main` branch.
    *   Provide a clear title and description of your changes.
    *   Reference any relevant issues.

## 🧩 Developing New Modules

The core of Nexus Drone is its modularity. All new sound sources, effects, and generative tools should inherit from the `NexusModule` base class.

### Module Checklist

*   **Header (`.h`):** Define the module class, its internal components, and public methods.
*   **Source (`.cpp`):** Implement the `process()`, `handleInput()`, `serialize()`, and `deserialize()` methods.
*   **Documentation:** Add Doxygen-style comments to your class and methods.
*   **Integration:** Add your module's source files to the `CMakeLists.txt` in the appropriate section (e.g., `MODULE_SOURCES`).

## ✍️ Code Style

*   **Naming:** Use `PascalCase` for classes and `camelCase` for variables and functions.
*   **Comments:** Use Doxygen for API documentation.
*   **Formatting:** Follow a consistent style (e.g., Allman or similar brace style).

We look forward to your contributions!
