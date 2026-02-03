# 🧊 Photorealistic Presentation of 3D Objects (OpenGL)

## Project Overview
This project is a **3D graphics application** developed in **C++ using OpenGL**. Its goal is to present 3D objects in a visually realistic environment using modern rendering techniques such as shader-based rendering, textured 3D models, a movable camera system, and a skybox.

The application renders a complete 3D scene that includes imported models, lighting effects, and environmental backgrounds. The project follows a **modular design**, where each major rendering component is implemented in a separate class.

---

## Features
- Modern OpenGL rendering pipeline
- Shader-based rendering using GLSL
- 3D model loading using OBJ files
- Texture loading with `stb_image`
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

## Camera System
The camera system allows navigation within the 3D scene and supports:
- Position and orientation control
- Perspective projection
- View matrix calculation
- Keyboard and mouse-based movement

This enables free movement and inspection of the scene.

---

## Skybox
A skybox is rendered using cubemap textures to create a surrounding environment. It improves visual realism and provides a consistent background for the entire scene.

---




