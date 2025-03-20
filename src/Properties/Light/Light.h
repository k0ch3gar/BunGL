#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>

struct LightData {
   alignas(16) glm::vec3 worldLightPos;
   alignas(16) glm::vec3 lightDirection;
   alignas(16) glm::vec4 color;
   alignas(4) float p;
   alignas(4) float kc;
   alignas(4) float kl;
   alignas(4) float kq;
   alignas(4) float coneAngle;
};

#endif //LIGHT_H
