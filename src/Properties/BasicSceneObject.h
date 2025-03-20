#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <memory>

#include "Attachable.h"
#include "IAttachable.h"
#include "Movable.h"
#include "Rotatable.h"
#include "Scalable.h"
#include "Updatable.h"
#include "Buffers/VertexAttributesBuffer.hpp"
#include "glm/glm.hpp"
#include "Shaders/Uniforms/UniformManager.hpp"


class BasicSceneObject : public Updatable, public UniformManager, public IAttachable, public IDrawable, public Movable, public Rotatable, public Scalable {
public:
    ~BasicSceneObject() override;

    explicit BasicSceneObject(IDrawable* vao);

    void RegisterUniforms(ShaderProgram *shader) override;

    void Draw() override;

    void Update(double delta) override;

    size_t AttachMovable(Movable *attachable) override;

    size_t AttachRotatable(Rotatable *attachable) override;

    size_t AttachScalable(Scalable *attachable) override;

private:
    IDrawable* _drawingStrategy;
    glm::mat4 _modelMatrix = glm::mat4(1.0f);
    Attachable _attachable;
};



#endif //DRAWABLE_H
