# Cellular Automata Graphics Engine (C++)

A lightweight C++ graphics engine built from scratch using OpenGL.  
Designed for learning, experimentation, and small projects such as simulations, cellular automata, and simple games.

---

## Features

- Modern OpenGL (3.3+ core profile)
- Batched 2D renderer (single draw call per frame)
- Solid color and textured shapes
- Multiple textures per frame
- Simple window + input system
- 2 sample cellular automata projects
- Minimal abstractions for ease of use
- `include/engine` contains the **public API**
- `src` contains **implementation details**
- `sample_projects` contains standalone executables built on top of the engine

---

## Dependencies

- **C++20**
- **OpenGL**
- **GLFW** (window/context creation)
- **GLAD** (OpenGL loader)
- **stb_image** (image loading)

---

## Using the Engine

### Initialization

1. Create a `.cpp`file with a main function and make sure to `#include engine.h`
        

2. initialize the library with `init(int width, int height)`




