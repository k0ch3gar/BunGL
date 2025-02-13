//
// Created by kosti on 12.02.2025.
//

#include "Camera.h"

#include "glm/ext/matrix_transform.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 up, glm::vec3 direction) {
    pos = position;
    _up = up;
    _direction = direction;

    _view = glm::mat4(1.0f);
}

glm::mat4 Camera::GetViewMatrix() {
    glm::vec4 front = rot * glm::vec4(0,0,-1, 1);
    _view = glm::lookAt(pos, pos + glm::vec3(front), _up);
    return _view;
}

Movable& Camera::Move(glm::vec3 diff) {
    glm::vec4 front = rot * glm::vec4(diff, 1);
    pos += front;
    return *this;
}
