#ifndef ILLUMABLE_H
#define ILLUMABLE_H
#include "Updatable.h"
#include "Buffers/ShaderStorageBuffer.hpp"
#include "glm/vec3.hpp"
#include "Light/Light.h"

class Illuminant final : public Updatable {
public:
    explicit Illuminant(LightData lightData) : _lightData(lightData) {}

    void Illuminate();

    void Update(double delta) override;

private:
    LightData _lightData;
};



#endif //ILLUMABLE_H
