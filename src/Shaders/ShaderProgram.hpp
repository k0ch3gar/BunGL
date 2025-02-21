#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP
#include <unordered_map>

#include "ShaderEnum.h"
#include "ShaderProcessor.hpp"
#include <glad/glad.h>
#include "glm/gtc/type_ptr.hpp"

class ShaderProgram {
public:

    explicit ShaderProgram(const GLuint shaderProgram) : _program(shaderProgram) {
        _uniformLocations.emplace(MVP, glGetUniformLocation(_program, "vp"));
        _uniformLocations.emplace(CameraNormal, glGetUniformLocation(_program, "cameraNormal"));

    }

    void UseProgram() const {
        glUseProgram(_program);
    }

    int GetUniform(const char* uniform) const {
        return glGetUniformLocation(_program, uniform);
    }

    void UniformMatrix(const std::string& uniformType, glm::mat4 data) const {
        const GLint glLoc = glGetUniformLocation(_program, uniformType.c_str());
        glUniformMatrix4fv(glLoc, 1, GL_FALSE, glm::value_ptr(data));
    }

    void UniformVector(const std::string& uniformType, const glm::vec3& data) const {
        const GLint glLoc = glGetUniformLocation(_program, uniformType.c_str());
        glUniform3fv(glLoc, 1, glm::value_ptr(data));
    }

private:
    GLuint _program;

    std::unordered_map<ShaderEnum, GLint> _uniformLocations;
};

#endif //SHADERPROGRAM_HPP
