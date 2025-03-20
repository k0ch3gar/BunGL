#include "Movable.h"

#include "glm/ext/matrix_transform.hpp"

Movable& Movable::Move(glm::vec3 diff) {
    pos += diff;
    return *this;
}

glm::vec3 Movable::GetPosition() const {
    return pos;
}
