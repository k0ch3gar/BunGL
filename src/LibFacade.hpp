#ifndef LIBFACADE_HPP
#define LIBFACADE_HPP

#include <Camera.h>
#include <fstream>
#include <iostream>
#include <glad/glad.h>
#include <Utils/ObjParser.hpp>

#include "../assets/testTriangle.h"
#include "Buffers/VAOBuilder.hpp"
#include "GLFW/glfw3.h"
#include "Properties/BasicSceneObject.h"

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
    // glEnable(GL_CULL_FACE);

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
    inline BasicSceneObject MakeDrawableFromObj(const char* pathToObj, int verticesLayout) {
        ObjParser parser;
        parser.parseOBJFile(pathToObj);

        ArrayBuffer vertices(parser.getVertices());
        ElementBuffer faces(parser.getFaces());
        auto* vao = new VertexAttributesBuffer();
        vao->AddAttribute(verticesLayout, &vertices, 3);
        vao->AddElementBuffer(&faces);

        return BasicSceneObject{vao};
    }

}

#endif //LIBFACADE_HPP
