#include "Scalable.h"

Scalable& Scalable::Scale(float size) {
    scale = glm::scale(scale, glm::vec3(size, size, size));
    return *this;
}
