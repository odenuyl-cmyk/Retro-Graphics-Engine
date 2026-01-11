#include <engine.h>

int main() {
    // Initialization

    Engine::init(1000, "example");

    while (!Engine::shouldClose()) {

        Engine::beginFrame();

        // Draw calls and per-frame updates

        Engine::endFrame();
    }

    Engine::closeWindow();

    return 0;
}