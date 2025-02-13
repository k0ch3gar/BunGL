#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "IDrawable.h"
#include "Movable.h"
#include "Buffers/VAOBuilder.hpp"
#include "Buffers/VertexArrayBuffer.hpp"
#include <glm/glm.hpp>


template<float* vertices, uint32_t* faces>
concept Triangles = requires()
{
    sizeof faces % 3 == 0;
};

class DrawableObject : public IDrawable, public Movable {
public:

    DrawableObject(std::vector<float>& vertices, std::vector<uint32_t>& faces) {
        VAOBuilder builder{};
        auto vertexArrayBuffer = builder
                .WithElementBuffer(faces)
                ->WithVertices(vertices)
                ->Build();

        _vertexArrayBuffer = new VertexArrayBuffer(vertexArrayBuffer);
    }

    void Draw() override;

    [[nodiscard]] glm::mat4 GetModel() const;

private:
    VertexArrayBuffer* _vertexArrayBuffer;
};



#endif //TRIANGLE_H
