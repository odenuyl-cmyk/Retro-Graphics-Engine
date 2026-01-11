#include <engine.h>
#include <iostream>
#include <ostream>

int main() {

    Engine::init(1000, "Hello World!");

    while (!Engine::shouldClose()) {
        Engine::beginFrame();

        if (Engine::keyHeld(Key::Space)) {
            Engine::drawText("Hello World!", .5, .5, 20, Engine::Color::YELLOW);
        }

        if (Engine::keyHeld(Key::Escape)) {
            break;
        }

        if (Engine::mouseHeld(Mouse::Left)) {
            std::cout << Engine::mouseX() << " " << Engine::mouseY() << std::endl;
        }

        Engine::endFrame();
    }

    Engine::closeWindow();
    return 0;
}

