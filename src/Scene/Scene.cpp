#include "Scene.h"

Scene::Scene(): _camera(nullptr), _eventHandler(nullptr) {}

Scene::~Scene() = default;

size_t Scene::AddUpdatable(Updatable* updatable) {
    _registries.emplace_back(updatable);
    return _registries.size() - 1;
}

void Scene::Update(double delta) {
    // _eventHandler->Update(delta);
    for (auto& x : _registries) {
        x->Update(delta);
    }
}
