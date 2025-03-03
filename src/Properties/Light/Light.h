#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>

struct LightData {
    glm::vec3 worldLightPos;
    glm::vec3 lightDirection;
    glm::vec4 color;
    float p;
    float kc;
    float kl;
    float kq;
};

#endif //LIGHT_H
