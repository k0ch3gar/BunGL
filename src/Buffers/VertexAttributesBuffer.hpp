#ifndef VERTEXARRAYBUFFER_HPP
#define VERTEXARRAYBUFFER_HPP

#include <cstdint>
#include <glad/glad.h>

#include "ArrayBuffer.hpp"
#include "ElementBuffer.hpp"

class VertexAttributesBuffer {
    uint32_t _vao{};
    size_t _elementsCount = 0;


    void Bind() const {
        glad_glBindVertexArray(_vao);
    }

    static void Unbind() {
        glad_glBindVertexArray(0);
    }

public:

    VertexAttributesBuffer() {
        glad_glGenVertexArrays(1, &_vao);
    }

    VertexAttributesBuffer& AddAttribute(int attributeIndex, ArrayBuffer* arrayBuffer, int size) {
        Bind();
        arrayBuffer->Bind();
        glVertexAttribPointer(attributeIndex, size, GL_FLOAT, GL_FALSE, size * sizeof(float), nullptr);
        glEnableVertexAttribArray(attributeIndex);
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            throw std::runtime_error("Vertex attribute array buffer adding failed");
        }

        Unbind();
        arrayBuffer->Unbind();

        return *this;
    }

    VertexAttributesBuffer& AddElementBuffer(ElementBuffer* elementBuffer) {
        Bind();
        elementBuffer->Bind();
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            throw std::runtime_error("Vertex attribute array buffer adding failed");
        }

        _elementsCount = elementBuffer->Size();
        Unbind();
        elementBuffer->Unbind();
        return *this;
    }

    void DrawTriangles() const {
        Bind();
        glDrawElements(
                GL_TRIANGLES,
             static_cast<int>(_elementsCount),
            GL_UNSIGNED_INT,
            nullptr);
        Unbind();
    }
};

#endif //VERTEXARRAYBUFFER_HPP
