#pragma once

#include <string>

struct rgb_t {
    float r, g, b, a;
};

void background(rgb_t color);

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, rgb_t color);

void drawRect(float x, float y, float width, float height, rgb_t color);

void drawImage(unsigned int textureID, float x, float y, float width, float height, rgb_t tint={1,1,1,1});

void drawText(std::string text, float x, float y1, int size, rgb_t color);

// RGB function and color macros
rgb_t rgb(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);

#define RED rgb(255, 0, 0, 255)
#define ORANGE rgb(255, 118, 0, 255)
#define YELLOW rgb(255, 255, 0, 255)
#define GREEN rgb(0, 255, 0, 255)
#define BLUE rgb(0, 0, 255, 255)
#define INDIGO rgb(63, 0, 255, 255)
#define VIOLET rgb(176, 0, 255, 255)
#define WHITE rgb(255, 255, 255, 255)
#define BLACK rgb(0, 0, 0, 255)
#define GREY rgb(128, 128, 128, 255)