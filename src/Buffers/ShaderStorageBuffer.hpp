#ifndef SHADERSTORAGEBUFFER_HPP
#define SHADERSTORAGEBUFFER_HPP
#include <iostream>

#include "Buffer.hpp"
#include "glm/glm.hpp"

class ShaderStorageBuffer : public Buffer<GL_SHADER_STORAGE_BUFFER, glm::mat4> {
public:
    explicit ShaderStorageBuffer(std::vector<glm::mat4>& data) {
        Fill<GL_DYNAMIC_DRAW>(data);

        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }
    }

private:
};

#endif //SHADERSTORAGEBUFFER_HPP
