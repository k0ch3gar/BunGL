//
// Created by kosti on 28.12.2024.
//

#include "Renderer.h"

#include <iostream>

size_t Renderer::AddDrawable(IDrawable *drawable) {
    _drawables.push_back(drawable);
    return _drawables.size() - 1;
}

bool Renderer::RemoveDrawable(size_t drawableId) {
    if (drawableId > _drawables.size()) return false;
    std::swap(
    _drawables.at(drawableId),
    _drawables.at(_drawables.size() - 1));

    _drawables.pop_back();
    return true;
}

void Renderer::Render() {
    for (const auto &drawable : _drawables) {
        drawable->Draw();
        auto error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }
    }
}
