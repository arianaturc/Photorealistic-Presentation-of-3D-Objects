# 🧊 Photorealistic Presentation of 3D Objects (OpenGL)

## Project Overview
This project is a **3D graphics application** developed in **C++ using OpenGL**. Its goal is to present 3D objects in a visually realistic environment using modern rendering techniques such as shader-based rendering, textured 3D models, a movable camera system, and a skybox.

The application renders a complete 3D scene that includes imported models, lighting effects, and environmental backgrounds. The project follows a **modular design**, where each major rendering component is implemented in a separate class.

---

## Features
- Modern OpenGL rendering pipeline
- Shader-based rendering using GLSL
- 3D model loading using OBJ files
- Skybox rendering using cubemap textures
- Movable camera with perspective projection
- Window and input handling
- Real-time rendering loop

---

## Technologies Used
- **C++**
- **OpenGL**
- **GLFW** – window creation and input handling
- **GLAD** – OpenGL function loading
- **GLM** – mathematical operations for graphics
- **stb_image** – texture loading
- **tinyobjloader** – loading OBJ 3D models

---

## Rendering Pipeline
The project follows the modern OpenGL pipeline:
1. Window and OpenGL context initialization
2. Shader compilation and linking
3. Loading 3D models and textures
4. Setting up vertex buffers and vertex arrays
5. Applying model, view, and projection matrices
6. Rendering 3D objects
7. Rendering the skybox as the background
8. Continuous real-time rendering loop

---

## Implementation Details


### Application Initialization
The application starts in `main.cpp`, where the window and OpenGL context are created. The program initializes all required OpenGL states, enables depth testing, and prepares the main rendering loop. Asset directories for shaders, models, and skybox textures are loaded at startup to ensure all resources are available during rendering.

---

### Window Management
The `Window` class encapsulates window creation and input handling using GLFW. It is responsible for:
- Creating the OpenGL context
- Managing window resizing
- Handling keyboard and mouse input
- Updating the viewport when the window size changes

This separation ensures that rendering logic remains independent of platform-specific window management.

---

### Shader System
The `Shader` class provides an abstraction over GLSL shader management. It:
- Loads vertex and fragment shader source files from the `shaders/` directory
- Compiles and links shader programs
- Performs error checking during compilation and linking
- Provides utility functions for setting uniform variables (matrices, vectors, lighting parameters)

All rendering in the application is shader-based and follows modern OpenGL practices.

---

### Camera System
The camera functionality is implemented in the `Camera` class. The camera supports:
- Free movement in the 3D scene
- Perspective projection
- View matrix computation based on position and orientation
- Keyboard-based movement and mouse-based rotation

The camera is updated every frame to allow smooth and responsive navigation within the scene.

---

### 3D Model Creation
Custom 3D models were created using **Blender** and exported as OBJ files. These models were integrated into the application without the use of third-party model loading libraries. Instead, the application directly processes the model data and renders it using its own mesh and rendering abstractions.


---

### Model and Mesh Handling
3D objects are handled using the `Model3D` and `Mesh` classes.

- `Model3D` is responsible for loading 3D models from OBJ files located in the `models/` directory.
- Model loading is performed using `tinyobjloader`, which parses vertex positions, normals, texture coordinates, and indices.
- Each model is composed of one or more `Mesh` objects.
- The `Mesh` class stores vertex data in vertex buffer objects (VBOs) and element buffer objects (EBOs) and manages vertex array objects (VAOs).

This structure allows efficient rendering and reuse of mesh data.


---

### Skybox Rendering
The skybox is implemented in the `SkyBox` class. It uses:
- A cubemap texture loaded from the `skybox/` directory
- A dedicated shader program optimized for skybox rendering
- A cube mesh rendered with depth testing adjusted to ensure the skybox appears behind all other objects

The skybox enhances realism by providing a surrounding environment for the scene.

---

### Scene Composition
Objects are placed within the scene using predefined transformation matrices. The `TreePositions` header contains predefined world-space positions used to place multiple instances of certain models consistently throughout the environment.

Each object undergoes:
- Model transformation
- View transformation (camera)
- Projection transformation

These matrices are passed to the shader each frame.

---

### Performance Considerations
- Depth testing is enabled to ensure correct object visibility
- Vertex data is uploaded once and reused every frame
- Modular design minimizes redundant calculations
- Efficient use of OpenGL buffers improves rendering performance

---
## 📷 GUI Preview
![GUI Screenshot](application_view.png)





