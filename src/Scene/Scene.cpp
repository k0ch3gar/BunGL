#include "Scene.h"

#include "Shaders/Uniforms/IntUniformable.hpp"

Scene::Scene(): numLights(0), _camera(nullptr), _eventHandler(nullptr) {
    _lightSources.BindBufferLayout(2);
}

Scene::~Scene() = default;

void Scene::RegisterUniforms(ShaderProgram *shader) {
    AddUniform(shader->GetUniform("lightNum"), new IntUniformable(&numLights));
    for (auto& x : std::ranges::views::values(_uniforms)) {
        x->RegisterUniforms(shader);
    }
}

size_t Scene::AddLight(LightData& lightData) {
     lightData.lightDirection = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(180.0f), glm::vec3(0, 1, 0)) * glm::vec4(lightData.lightDirection, 1));
    _lightIndex = _lightSources.Append(lightData);
    return _lightIndex;
}

size_t Scene::AddDrawable(IDrawable *drawable) {
    _drawables.emplace(_nextDrawableId, drawable);
    return _nextDrawableId++;
}

void Scene::UpdateLight(size_t index, const LightData &lightData) {
    _lightSources.ChangeBufferElement(lightData, index);
}

size_t Scene::AddRegistry(Updatable* updatable) {
    _registries.emplace_back(updatable);
    return _registries.size() - 1;
}

// size_t Scene::AddRegistry(UniformManager* Vregistry) {
//     _uniforms.emplace(_nextId, registry);
//     return _nextId++;
// }

size_t Scene::RegisterSceneObject(BasicSceneObject *object) {
    _uniforms.emplace(_nextUniformId, object);
    return _nextUniformId++;
}

void Scene::Update(double delta) {
    numLights = static_cast<int>(_lightSources.Size());
    Uniform();
    // LightData lightData = _lightSources.Get((int)_lightIndex);
    // lightData.coneAngle += 0.05f;
    // if (lightData.coneAngle > 90.0f) lightData.coneAngle = 0;
    // lightData.lightDirection = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(1.0f), glm::vec3(0, 1, 0)) * glm::vec4(lightData.lightDirection, 1));
    // _lightSources.Remove((int)_lightIndex);
    // _lightIndex = _lightSources.Append(lightData);
    for (auto& x : _registries) {
        x->Update(delta);
    }
}

void Scene::Draw() {
    for (const auto& x : std::ranges::views::values(_drawables)) {
        x->Draw();
    }
}
