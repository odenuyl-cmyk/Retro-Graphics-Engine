#pragma once

#include "keyboard_mouse_inputs.h"

namespace Input {
    void update();
    double mouseX();
    double mouseY();
    bool mouseHeld(mouseNum button);
    bool keyHeld(keyNum key);
}