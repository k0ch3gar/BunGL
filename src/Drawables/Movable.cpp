#include "Movable.h"

#include "glm/ext/matrix_transform.hpp"

Movable& Movable::RotateX(float xDegree) {
    rot = glm::rotate(rot, glm::radians(xDegree), glm::vec3(1.0f, 0.0f, 0.0f));
    return *this;
}

Movable& Movable::RotateY(float yDegree) {
    rot = glm::rotate(rot, glm::radians(yDegree), glm::vec3(0.0f, 1.0f, 0.0f));
    return *this;
}

Movable& Movable::RotateZ(float zDegree) {
    rot = glm::rotate(rot, glm::radians(zDegree), glm::vec3(0.0f, 0.0f, 1.0f));
    return *this;
}

Movable& Movable::Move(glm::vec3 diff) {
    pos += diff;
    return *this;
}

Movable & Movable::Scale(float size) {
    scale = glm::scale(scale, glm::vec3(size, size, size));
    return *this;
}
