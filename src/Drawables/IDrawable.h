#ifndef IDRAWABLE_H
#define IDRAWABLE_H

struct IDrawable {
    virtual ~IDrawable() = default;

    virtual void Draw() = 0;
};

#endif //IDRAWABLE_H