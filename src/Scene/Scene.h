#ifndef SCENE_H
#define SCENE_H
#include <Camera.h>
#include <vector>
#include <ranges>
#include <Drawables/IDrawable.h>
#include <Events/EventHandler.hpp>

#include "Updatable.h"
#include "Buffers/ShaderStorageBuffer.hpp"
#include "Properties/BasicSceneObject.h"
#include "Properties/Movable.h"
#include "Properties/Light/Light.h"
#include "Properties/Illuminant.h"


class Scene : public Updatable, public IDrawable, public UniformManager {
public:
    Scene();

    ~Scene() override;

    void RegisterUniforms(ShaderProgram *shader) override;

    size_t AddLight(LightData& lightData);

    size_t AddDrawable(IDrawable* drawable);

    void UpdateLight(size_t index, const LightData& lightData);

    void RemoveLight(size_t index);

    size_t AddRegistry(Updatable* updatable);

    // size_t AddRegistry(UniformManager* registry);

    size_t RegisterSceneObject(BasicSceneObject* object);

    void Update(double delta) override;

    void Draw() override;

private:
    std::vector<Updatable*> _registries;

    std::unordered_map<size_t, UniformManager*> _uniforms;
    int _nextUniformId = 0;

    std::unordered_map<size_t, IDrawable*> _drawables;
    int _nextDrawableId = 0;

    ShaderStorageBuffer<LightData> _lightSources;

    int numLights;

    Camera* _camera;

    EventHandler* _eventHandler;

    size_t _lightIndex;
};


#endif //SCENE_H
