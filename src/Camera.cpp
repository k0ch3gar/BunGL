//
// Created by kosti on 12.02.2025.
//

#include "Camera.h"

#include <iostream>
#include <ostream>
#include <glad/glad.h>

#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


Camera::Camera(glm::vec3 position, glm::vec3 up, glm::vec3 direction) {
    pos = position;
    _up = up;
    _direction = direction;
    _right = glm::cross(_direction, up);

    pitch = 0;
}

void Camera::Update(double delta) {
    // Move(glm::vec3(0,0,0.005f));
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(pos, pos + _direction, _up);
}

Camera& Camera::Move(glm::vec3 diff) {
    glm::vec4 front = rot * glm::vec4(diff * 0.005f, 1);
    pos += front;
    return *this;
}

Camera& Camera::RotateY(float yDegree) {
    rot = glm::rotate(glm::mat4(1), glm::radians(yDegree), glm::vec3(0, 1, 0)) * rot;
    _up = normalize(rot * glm::vec4(0, 1, 0, 0));
    _direction = normalize(rot * glm::vec4(0, 0, -1, 0));
    _right = normalize(rot * glm::vec4(1, 0, 0, 0));
    return *this;
}

void Camera::Uniform(int uniformPos) {
    glUniformMatrix4fv(uniformPos, 1, GL_FALSE, glm::value_ptr(GetViewMatrix()));
}

Camera& Camera::RotateX(float xDegree) {
    if (abs(pitch + xDegree) > 89.0f) return *this;
    pitch += xDegree;
    rot = glm::rotate(glm::mat4(1), glm::radians(xDegree), _right) * rot;
    _direction = normalize(rot * glm::vec4(0, 0, -1, 0));
    _up = normalize(rot * glm::vec4(0, 1, 0, 0));
    return *this;
}



