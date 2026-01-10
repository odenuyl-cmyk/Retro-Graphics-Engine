#pragma once


struct rgb_t {
    float r, g, b, a;
};

namespace Engine::Color {
    inline constexpr rgb_t RED = {1, 0, 0, 1};
    inline constexpr rgb_t ORANGE = {1, 118/255, 0, 1};
    inline constexpr rgb_t YELLOW = {1, 1, 0, 1};
    inline constexpr rgb_t GREEN = {0, 1, 0, 1};
    inline constexpr rgb_t BLUE = {0, 0, 1, 1};
    inline constexpr rgb_t INDIGO = {63/255, 0, 1, 1};
    inline constexpr rgb_t VIOLET = {176/255, 0, 1, 1};
    inline constexpr rgb_t WHITE = {1, 1, 1, 1};
    inline constexpr rgb_t BLACK = {0, 0, 0, 1};
    inline constexpr rgb_t GREY = {.5, .5, .5, 1};
}