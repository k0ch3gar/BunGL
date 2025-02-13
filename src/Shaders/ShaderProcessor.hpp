#ifndef SHADERPROCESSOR_HPP
#define SHADERPROCESSOR_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Utils/FileUtils.h"

class ShaderProcessor {


public:
    GLuint CompileShader(GLenum type, const std::string &pathToShader) {
        auto rawShaderData = std::move(ReadFile(pathToShader));
        std::ostringstream stream;
        stream << rawShaderData.rdbuf();
        auto rawStrShaderData = stream.str();
        const char* rawChShaderData = rawStrShaderData.c_str();
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &rawChShaderData, nullptr);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Ошибка компиляции шейдера: " << infoLog << std::endl;
            exit(EXIT_FAILURE);
        }

        return shader;
    }

    uint32_t GenShaderProgram(const std::string &vertexShaderSource,
        const std::string &fragmentShaderSource,
        const std::string& geometryShaderSource) {
        GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
        GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
        GLuint geometryShader = CompileShader(GL_GEOMETRY_SHADER, geometryShaderSource);

        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glAttachShader(shaderProgram, geometryShader);
        glLinkProgram(shaderProgram);

        int success;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
            std::cerr << "Ошибка линковки шейдерной программы: " << infoLog << std::endl;
            exit(EXIT_FAILURE);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return shaderProgram;
    }
};



#endif //SHADERPROCESSOR_HPP
