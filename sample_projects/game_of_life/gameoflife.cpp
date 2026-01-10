#include <iostream>
#include "GOL_helpers.h"
#include <engine.h>
#include <thread>
#include <chrono>
using namespace std;
using namespace Window;
using namespace Input;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;
    const float wStep = 1.0f / float(cols);
    const float hStep = 1.0f / float(rows);
    frameRate(144);

    initPixels(pixels);
    initPixels(copyPixels);
    init(screenWidth, screenHeight);

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

        if (keyPressed(KEY_SPACE)) {
            paused = false;
        }

        if (keyPressed(KEY_ESCAPE)) {
            break;
        }

        if (0 <= mouseX() && mouseX() <= screenWidth && 0 <= mouseY() && mouseY() < screenHeight) {
            if (mousePressed(0)) {
                paused = true;
                frameRate(144);
                int squareWidth = screenWidth / cols;
                int squareHeight = screenHeight / rows;
                int x = mouseX()/squareWidth;
                int y = mouseY()/squareHeight;
                add(y*cols + x);
            } else if (mousePressed(1)) {
                paused = true;
                frameRate(144);
                int squareWidth = screenWidth / cols;
                int squareHeight = screenHeight / rows;
                int x = mouseX()/squareWidth;
                int y = mouseY()/squareHeight;
                remove(y*cols + x);
            }
        }

        std::string text = "Generation: " + std::to_string(generation);
        drawRect(0.035, .9, 0.325 + 0.02*int(log10(generation+1)), 0.06, GREY);
        drawText(text, -0.9f, -0.9f, 1, GREEN);

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