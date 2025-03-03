//
// Created by kosti on 01.03.2025.
//

#include "Drawable.h"

#include <Shaders/ShaderProgram.hpp>

Drawable::~Drawable() = default;

Drawable::Drawable(VertexAttributesBuffer vao) :
    _vertexAttributes(vao) {}

void Drawable::Draw() {
    _vertexAttributes.DrawTriangles();
}

void Drawable::Uniform(int uniformPos) {
    glUniformMatrix4fv(uniformPos, 1, GL_FALSE, glm::value_ptr(this->rot));
}

void Drawable::Update(double delta) {
    Draw();
}
