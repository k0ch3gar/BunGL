#ifndef SCENE_H
#define SCENE_H
#include <Camera.h>
#include <vector>
#include <Drawables/IDrawable.h>
#include <Events/EventHandler.hpp>

#include "Updatable.h"
#include "Buffers/ShaderStorageBuffer.hpp"
#include "Properties/Movable.h"
#include "Properties/Light/Light.h"
#include "Properties/Illuminant.h"


class Scene : public Updatable {
public:
    Scene();

    ~Scene() override;

    size_t AddLight(const LightData& lightData);

    void UpdateLight(size_t index, const LightData& lightData);

    void RemoveLight(size_t index);

    size_t AddUpdatable(Updatable* updatable);

    void Update(double delta) override;

private:
    std::vector<Updatable*> _registries;

    ShaderStorageBuffer<LightData> _lightSources;

    Camera* _camera;

    EventHandler* _eventHandler;
};


#endif //SCENE_H
