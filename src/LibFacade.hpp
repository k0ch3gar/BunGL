#ifndef LIBFACADE_HPP
#define LIBFACADE_HPP

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

#endif //LIBFACADE_HPP
