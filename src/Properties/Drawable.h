#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <memory>

#include "Movable.h"
#include "Rotatable.h"
#include "Scalable.h"
#include "Updatable.h"
#include "Buffers/VertexAttributesBuffer.hpp"
#include "glm/glm.hpp"
#include "Shaders/Uniforms/UniformManager.hpp"


class Drawable : public Updatable, public UniformManager, public Rotatable, public Scalable {
public:
    ~Drawable() override;

    explicit Drawable(VertexAttributesBuffer vao);

    void RegisterUniforms(ShaderProgram *shader) override;

    virtual void Draw();

    void Update(double delta) override;

private:
    VertexAttributesBuffer _vertexAttributes;
    glm::mat4 _modelMatrix = glm::mat4(1.0f);
};



#endif //DRAWABLE_H
