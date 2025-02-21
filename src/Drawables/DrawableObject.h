#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "IDrawable.h"
#include "Properties/Movable.h"
#include "Buffers/VAOBuilder.hpp"
#include "Buffers/VertexAttributesBuffer.hpp"
#include <glm/glm.hpp>


template<float* vertices, uint32_t* faces>
concept Triangles = requires()
{
    sizeof faces % 3 == 0;
};

class DrawableObject : public IDrawable, public Movable {
public:

    DrawableObject() = default;

    DrawableObject(std::vector<float>& vertices, std::vector<uint32_t>& faces) {
        VAOBuilder builder{};
        _vertexArrayBuffer = builder
                .WithElementBuffer(faces)
                .WithVertices(vertices)
                .Build();
    }

    void SetVAO(VertexAttributesBuffer vao) {
        _vertexArrayBuffer = vao;
    }

    void Draw() override;

    [[nodiscard]] glm::mat4 GetModel() const;

private:
    VertexAttributesBuffer _vertexArrayBuffer;
};

#endif //TRIANGLE_H
