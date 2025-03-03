#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <memory>

#include "Movable.h"
#include "Rotatable.h"
#include "Updatable.h"
#include "Buffers/VertexAttributesBuffer.hpp"
#include "Shaders/IUniform.h"
#include "glm/glm.hpp"


class Drawable : public Updatable, public IUniform, public Rotatable {
public:
    ~Drawable() override;

    explicit Drawable(VertexAttributesBuffer vao);

    virtual void Draw();

    void Uniform(int uniformPos) override;

    void Update(double delta) override;

private:
    VertexAttributesBuffer _vertexAttributes;
};



#endif //DRAWABLE_H
