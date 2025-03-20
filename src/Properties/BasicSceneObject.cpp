#include "BasicSceneObject.h"

#include <Shaders/ShaderProgram.hpp>
#include <utility>
#include <Drawables/IDrawable.h>

#include "Shaders/Uniforms/Mat4Uniformable.hpp"

BasicSceneObject::~BasicSceneObject() = default;

BasicSceneObject::BasicSceneObject(IDrawable* vao) : _drawingStrategy(vao) {
}

void BasicSceneObject::RegisterUniforms(ShaderProgram *shader) {
    AddUniform(shader->GetUniform("model"), new Mat4Uniformable(&_modelMatrix));
}

void BasicSceneObject::Draw() {
    _drawingStrategy->Draw();
}

void BasicSceneObject::Update(double delta) {
    _modelMatrix = glm::translate(glm::mat4(1.0f), pos) * rot * scale;
    Uniform();
    Draw();
}

void Unif() {
    Uniform();
}

void Draw() {
    Uniform();
    ...;
}

size_t BasicSceneObject::AttachMovable(Movable *attachable) {
    return _attachable.AttachMovable(attachable);
}

size_t BasicSceneObject::AttachRotatable(Rotatable *attachable) {
    return _attachable.AttachRotatable(attachable);
}

size_t BasicSceneObject::AttachScalable(Scalable *attachable) {
    return _attachable.AttachScalable(attachable);
}