//
// Created by kosti on 28.12.2024.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <vector>

#include "Drawables/IDrawable.h"
#include "glm/fwd.hpp"
#include "Shaders/ShaderProgram.hpp"


class Renderer {
public:
    size_t AddDrawable(IDrawable *drawable);

    bool RemoveDrawable(size_t drawableId);

    void Render();

private:
    std::vector<IDrawable*> _drawables;
};



#endif //RENDERER_H
