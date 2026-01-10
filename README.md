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

---

## Project Structure
Graphics_Engine/     
├── include/    
│       └── engine/ 
│ ├── window.h # Public window API  
│ ├── renderer.h # Public rendering API 
│ ├── textures.h # Texture loading interface    
│   
├── src/    
│ ├── window.cpp    
│ ├── window_internal.h # Private engine-only internals 
│ ├── renderer.cpp  
│ ├── textures.cpp  
│ └── input.cpp 
│   
├── sample_projects/    
│          ├── game_of_life/     
│          │ ├── gameoflife.cpp  
│          │ └── CMakeLists.txt  
│   
├── CMakeLists.txt  
└── README.md   


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



---
## bbdafbadsfba





[//]: # (## Building)

[//]: # ()
[//]: # (### Prerequisites)

[//]: # ()
[//]: # (Make sure the following are installed and available to CMake:)

[//]: # ()
[//]: # (- CMake 3.20+)

[//]: # (- A C++20-compatible compiler)

[//]: # (- GLFW)

[//]: # (- GLAD)

[//]: # (- stb_image)

[//]: # ()
[//]: # (### Build Steps)

[//]: # ()
[//]: # (```bash)

[//]: # (mkdir build)

[//]: # (cd build)

[//]: # (cmake ..)

[//]: # (cmake --build .)

