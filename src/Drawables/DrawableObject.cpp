//
// Created by kosti on 28.12.2024.
//

#include "DrawableObject.h"

#include <stdexcept>

#include "glm/ext/matrix_transform.hpp"


void DrawableObject::Draw() {
    _vertexArrayBuffer->DrawTriangles();
    auto error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL error: " << error << std::endl;
    }
}

glm::mat4 DrawableObject::GetModel() const {
    return glm::translate(glm::mat4(1.0f), this->pos) * this->rot * this->scale;
}
