#ifndef ELEMENTBUFFER_HPP
#define ELEMENTBUFFER_HPP
#include <iostream>
#include <stdexcept>
#include <glad/glad.h>

#include "Buffer.hpp"


class ElementBuffer : public Buffer<GL_ELEMENT_ARRAY_BUFFER, uint32_t> {
public:

    explicit ElementBuffer() = default;


    explicit ElementBuffer(std::vector<uint32_t>& faces) {
        this->Fill<GL_STATIC_DRAW>(faces);

        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }
    }
};


#endif //ELEMENTBUFFER_HPP
