#ifndef VERTEXARRAYBUFFER_HPP
#define VERTEXARRAYBUFFER_HPP

#include <cstdint>
#include <glad/glad.h>

#include "ArrayBuffer.hpp"
#include "ElementBuffer.hpp"

class VertexArrayBuffer {
    uint32_t _vao{};
    ArrayBuffer* _arrayBuffer;
    ElementBuffer* _elementBuffer;


    void Bind() {
        glad_glBindVertexArray(_vao);
    }

    void Unbind() {
        glad_glBindVertexArray(0);
    }

public:

    VertexArrayBuffer(ArrayBuffer* arrayBuffer, ElementBuffer* elementBuffer) {
        _arrayBuffer = arrayBuffer;
        _elementBuffer = elementBuffer;

        glad_glGenVertexArrays(1, &_vao);

        Bind();

        _arrayBuffer->Bind();
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }

        _elementBuffer->Bind();
        Unbind();

        _arrayBuffer->Unbind();
        _elementBuffer->Unbind();
        error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }
    }

    void DrawTriangles() {
        Bind();
        glDrawElements(
                GL_TRIANGLES,
             _elementBuffer->Size(),
            GL_UNSIGNED_INT,
            nullptr);
        Unbind();
    }
};

#endif //VERTEXARRAYBUFFER_HPP
