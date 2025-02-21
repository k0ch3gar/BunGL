#include "Scene.h"

void Scene::Draw() {
    for (const auto& drawable : _drawables) {
        drawable->Draw();
    }
}
