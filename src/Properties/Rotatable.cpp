#include "Rotatable.h"


Rotatable& Rotatable::RotateX(float xDegree) {
    rot = glm::rotate(rot, glm::radians(xDegree), glm::vec3(1.0f, 0.0f, 0.0f));
    return *this;
}

Rotatable& Rotatable::RotateY(float yDegree) {
    rot = glm::rotate(rot, glm::radians(yDegree), glm::vec3(0.0f, 1.0f, 0.0f));
    return *this;
}

Rotatable& Rotatable::RotateZ(float zDegree) {
    rot = glm::rotate(rot, glm::radians(zDegree), glm::vec3(0.0f, 0.0f, 1.0f));
    return *this;
}
