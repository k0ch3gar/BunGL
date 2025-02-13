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
        _uniformLocations.emplace(MVP, glGetUniformLocation(_program, "mvp"));
        _uniformLocations.emplace(CameraNormal, glGetUniformLocation(_program, "cameraNormal"));

    }

    void UseProgram() const {
        glUseProgram(_program);
    }

    void UniformMatrix(ShaderEnum uniformType, glm::mat4 data) const {
        const GLint glLoc = _uniformLocations.at(uniformType);
        glUniformMatrix4fv(glLoc, 1, GL_FALSE, glm::value_ptr(data));
    }

    void UniformVector(ShaderEnum uniformType, const glm::vec3& data) const {
        const GLint glLoc = _uniformLocations.at(uniformType);
        glUniform3fv(glLoc, 1, glm::value_ptr(data));
    }

private:
    GLuint _program;

    std::unordered_map<ShaderEnum, GLint> _uniformLocations;
};

#endif //SHADERPROGRAM_HPP
