#include "../include/window.h"
#include "../include/input.h"
#include "../include/keyboard_mouse_inputs.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Input {

    static double mouseXPos = 0;
    static double mouseYPos = 0;

    void update() {
        glfwGetCursorPos(Window::getWindow(), &mouseXPos, &mouseYPos);
        glfwPollEvents();
    }

    double mouseX() {
        return mouseXPos;
    }

    double mouseY() {
        return mouseYPos;
    }

    bool mouseHeld(const mouseNum button) {
        GLFWwindow* window = glfwGetCurrentContext();
        return glfwGetMouseButton(window, button) == GLFW_PRESS;
    }

    bool keyHeld(const keyNum key) {
        GLFWwindow* window = Window::getWindow();
        return glfwGetKey(window, key) == GLFW_PRESS;
    }
}