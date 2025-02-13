#ifndef VERTEXBUFFER_HPP
#define VERTEXBUFFER_HPP
#include <stdexcept>
#include <array>
#include <iostream>

#include "Buffer.hpp"
#include "glm/vec3.hpp"

class ArrayBuffer : public Buffer<GL_ARRAY_BUFFER, float> {
public:

    explicit ArrayBuffer() = default;

    explicit ArrayBuffer(std::vector<float>& vertices) {
        this->Fill<GL_STATIC_DRAW>(vertices);

        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }
    }

private:
    glm::vec3 *_data{};
};

#endif //VERTEXBUFFER_HPP
