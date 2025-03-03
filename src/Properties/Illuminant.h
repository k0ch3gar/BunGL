#ifndef ILLUMABLE_H
#define ILLUMABLE_H
#include "Buffers/ShaderStorageBuffer.hpp"
#include "glm/vec3.hpp"
#include "Light/Light.h"

class Illuminant {
public:
    virtual ~Illuminant() = default;

    virtual void Illuminate() = 0;
};



#endif //ILLUMABLE_H
