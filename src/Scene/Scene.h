#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <Drawables/IDrawable.h>

#include "Updatable.h"
#include "Properties/Movable.h"


class Scene : public IDrawable, public Updatable {
public:
    Scene() = default;

    size_t AddDrawable(IDrawable* drawable);

    size_t AddMovable(Movable* movable);

    void Draw() override;

    void Update(double delta) override;

private:
    std::vector<IDrawable *> _drawables;
    std::vector<Movable *> _movables;
};


#endif //SCENE_H
