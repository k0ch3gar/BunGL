//
// Created by kosti on 12.02.2025.
//

#include "Camera.h"

#include <iostream>
#include <ostream>
#include <glad/glad.h>

#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Shaders/Uniforms/Mat4Uniformable.hpp"
#include "Shaders/Uniforms/Vec3Uniformable.hpp"


Camera::Camera(glm::vec3 position, glm::vec3 up, glm::vec3 direction) {
    pos = position;
    _up = up;
    _direction = direction;
    _right = glm::cross(_direction, up);

    _pitch = 0;
    _view = glm::lookAt(pos, pos + _direction, up);
}

void Camera::Update(double delta) {
    _view = glm::lookAt(pos, pos + _direction, _up);
    Uniform();
}

void Camera::RegisterUniforms(ShaderProgram *shader) {
    AddUniform(shader->GetUniform("v"), new Mat4Uniformable(&_view));
    AddUniform(shader->GetUniform("cameraNormal"), new Vec3Uniformable(&_direction));
    AddUniform(shader->GetUniform("cameraWorldPos"), new Vec3Uniformable(&pos));
}

glm::mat4 Camera::GetViewMatrix() const {
    return _view;
}

glm::vec3 Camera::GetDirection() const {
    return _direction;
}

Camera& Camera::Move(glm::vec3 diff) {
    glm::vec4 front = rot * glm::vec4(diff * 0.005f, 1);
    pos += front;
    _attachable.Move(diff * 0.005f);
    return *this;
}

Camera& Camera::RotateY(float yDegree) {
    rot = glm::rotate(glm::mat4(1), glm::radians(yDegree), glm::vec3(0, 1, 0)) * rot;
    _up = normalize(rot * glm::vec4(0, 1, 0, 0));
    _direction = normalize(rot * glm::vec4(0, 0, -1, 0));
    _right = normalize(rot * glm::vec4(1, 0, 0, 0));
    _attachable.Rotate(0, yDegree, 0);
    return *this;
}

size_t Camera::AttachMovable(Movable *attachable) {
    return _attachable.AttachMovable(attachable);
}

size_t Camera::AttachRotatable(Rotatable *attachable) {
    return _attachable.AttachRotatable(attachable);
}

size_t Camera::AttachScalable(Scalable *attachable) {
    return _attachable.AttachScalable(attachable);
}

Camera& Camera::RotateX(float xDegree) {
    if (abs(_pitch + xDegree) > 89.0f) return *this;
    _pitch += xDegree;
    rot = glm::rotate(glm::mat4(1), glm::radians(xDegree), _right) * rot;
    _direction = normalize(rot * glm::vec4(0, 0, -1, 0));
    _up = normalize(rot * glm::vec4(0, 1, 0, 0));
    _attachable.Rotate(xDegree, 0, 0);
    return *this;
}



