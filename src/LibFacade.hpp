#ifndef LIBFACADE_HPP
#define LIBFACADE_HPP

#include <Camera.h>
#include <fstream>
#include <iostream>
#include <glad/glad.h>

#include "GLFW/glfw3.h"

inline bool InitLib() {
    if (!glfwInit()) {
        return false;
    }

    return true;
}

inline bool InitRender() {
    if(!gladLoadGL()) {
        return false;
    }

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Ошибка загрузки OpenGL!" << std::endl;
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    return true;
}

template<typename T>
void parseData(const char* pathToFile, std::vector<T>& vec) {
    std::ifstream file(pathToFile);
    T num;
    while (file >> num) {
        vec.emplace_back(num);
    }
}

namespace bunGL {
    inline Window* window = nullptr;

    void InitWindow(int width, int height, const char *title, float fov) {
        window = new Window(width, height, title, fov);
    }

    void RegisterBasicCamera() {
    }

    void RegisterObject() {

    }
}

#endif //LIBFACADE_HPP
