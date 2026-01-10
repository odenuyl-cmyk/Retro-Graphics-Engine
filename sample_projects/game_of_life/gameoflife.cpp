#include <iostream>
#include "GOL_helpers.h"
#include <engine.h>
#include <thread>
#include <chrono>
using namespace std;
using namespace Window;
using namespace Input;

int main() {
    const int screenSize = 800;
    const float wStep = 1.0f / float(cols);
    const float hStep = 1.0f / float(rows);
    frameRate(144);

    initPixels(pixels);
    initPixels(copyPixels);
    init(screenSize, "Conway's Game of Life");

    bool paused = true;
    int generation = 0;


    while (!shouldClose()) {
        beginFrame();
        background(BLACK);
        for (int i = 0; i < rows*cols; i++) {
            int row = i/cols;
            int col = i%cols;
            if (pixels[i]) {
                drawRect(float(col)*wStep, float(row)*hStep, wStep, hStep, YELLOW);
            }
        }

        if (Input::keyHeld(Key::Space)) {
            paused = false;
        }

        if (Input::keyHeld(Key::Escape)) {
            break;
        }

        if (0 <= mouseX() && mouseX() <= screenSize && 0 <= mouseY() && mouseY() < screenSize) {
            if (Input::mouseHeld(Mouse::Left)) {
                paused = true;
                frameRate(144);
                int squareSize = screenSize / cols;
                int x = mouseX()/squareSize;
                int y = mouseY()/squareSize;
                add(y*cols + x);
            } else if (Input::mouseHeld(Mouse::Right)) {
                paused = true;
                frameRate(144);
                int squareSize = screenSize / cols;
                int x = mouseX()/squareSize;
                int y = mouseY()/squareSize;
                remove(y*cols + x);
            }
        }

        std::string text = "Generation: " + std::to_string(generation);
        drawRect(0.035, .9, 0.325 + 0.02*int(log10(generation+1)), 0.06, GREY);
        drawText(text, .2, .917, 20, GREEN);

        if (!paused) {
            frameRate(10);
            step();
            generation++;
        }
        endFrame();
    }

    closeWindow();
    return 0;

}