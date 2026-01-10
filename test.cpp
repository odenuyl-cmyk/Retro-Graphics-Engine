#include <engine.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using point = tuple<int, int>;

int main() {

    //int screenSize;
    //std::cout << "Desired Screen Size: " << std::endl;
    //std::cin >> screenSize;
    int screenSize = 1000;
    Window::init(screenSize, "Test");
    float fps = 144.0f;
    Window::frameRate(fps);

    std::string g = "assets/textures/crab.png";
    unsigned int crabImage = makeTexture(g);

    //std::string text = "FPS: 30";


    int counter = 0;

    while (!Window::shouldClose())
    {
        Window::beginFrame();

        if (Input::keyHeld(Key::Escape)) {
            break;
        }

        if (Input::mouseHeld(Mouse::Middle)) {
            std::cout << "hi" << std::endl;
        }

        for (int j = 0; j < 25; j++) {
            for (int i = 0; i < 13; i++) {
                drawRect(i*0.08 + 0.04*(j%2), j*0.04, .04, .04, RED);
            }
        }

        std::string text = "Frames: " + std::to_string(counter) + " Seconds: " + std::to_string(counter/fps);
        drawText(text, .5, .8, 20, YELLOW);
        drawText("GAME OVER", .5, .5, 100, GREEN);

        drawImage(crabImage, 0, 0, .5, .5, rgb(90, 170, 200, 205));
        //std::cout << Input::mouseX() << " " << Input::mouseY() << std::endl;


        Window::endFrame();
        counter++;
    }

    Window::closeWindow();

    return counter;
}
