#include "Drawable.h"

#include <Shaders/ShaderProgram.hpp>
#include "Shaders/Uniforms/Mat4Uniformable.hpp"

Drawable::~Drawable() = default;

Drawable::Drawable(VertexAttributesBuffer vao) : _vertexAttributes(vao) {
}

void Drawable::RegisterUniforms(ShaderProgram *shader) {
    AddUniform(shader->GetUniform("model"), new Mat4Uniformable(&_modelMatrix));
}

void Drawable::Draw() {
    _vertexAttributes.DrawTriangles();
}

void Drawable::Update(double delta) {
    RotateY(0.1f);
    _modelMatrix = scale * rot;
    Uniform();
    Draw();
}
