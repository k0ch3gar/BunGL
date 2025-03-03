#ifndef SHADERBUILDER_HPP
#define SHADERBUILDER_HPP
#include <list>
#include <string>
#include <glad/glad.h>

#include "ShaderEnum.h"
#include "ShaderProcessor.hpp"
#include "ShaderProgram.hpp"

class ShaderBuilder {
public:

    ShaderBuilder() {
        _shaderProgram = glCreateProgram();
    }

    ShaderBuilder& AttachVertexShader(const std::string& filePath) {
        AttachShader(GL_VERTEX_SHADER, filePath);
        return *this;
    }

    ShaderBuilder& AttachFragmentShader(const std::string& filePath) {
        AttachShader(GL_FRAGMENT_SHADER, filePath);
        return *this;
    }

    ShaderBuilder& AttachGeometryShader(const std::string& filePath) {
        AttachShader(GL_GEOMETRY_SHADER, filePath);
        return *this;
    }

    ShaderProgram Build() {
        for (const auto &shader: _shaders | std::views::values) glAttachShader(_shaderProgram, shader);
        glLinkProgram(_shaderProgram);

        int success;
        glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(_shaderProgram, 512, nullptr, infoLog);
            std::cerr << "Ошибка линковки шейдерной программы: " << infoLog << std::endl;
            exit(EXIT_FAILURE);
        }

        for (auto& [_, shader] : _shaders) glDeleteShader(shader);
        _shaders.clear();
        GLuint result = _shaderProgram;
        _shaderProgram = glCreateProgram();
        return ShaderProgram(result);
    }


private:
    void AttachShader(const GLenum shaderType, const std::string& filePath) {
        const auto vertexShader = _shaderProcessor.CompileShader(shaderType, filePath);
        _shaders[shaderType] = vertexShader;
    }

    GLuint _shaderProgram;
    ShaderProcessor _shaderProcessor{};
    std::unordered_map<GLenum, GLuint> _shaders;
};

#endif //SHADERBUILDER_HPP
