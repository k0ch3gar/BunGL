//
// Created by kosti on 20.02.2025.
//

#include "Illuminant.h"

#include "glm/glm.hpp"
#include "glm/ext/matrix_transform.hpp"

void Illuminant::Update(double delta) {
    _lightData.lightDirection = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(0.1f), glm::vec3(0, 0, 1)) * glm::vec4(_lightData.lightDirection, 1));
}
