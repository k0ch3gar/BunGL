#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP
#include <ranges>
#include <unordered_map>
#include <memory>

#include "ShaderEnum.h"
#include "ShaderProcessor.hpp"
#include <glad/glad.h>

#include "IUniform.h"
#include "glm/gtc/type_ptr.hpp"

class ShaderProgram : public Updatable {
public:
    ~ShaderProgram() override = default;

    explicit ShaderProgram(const GLuint shaderProgram) : _program(shaderProgram) {
    }

    void UseProgram() const {
        glUseProgram(_program);
    }

    void Update(double delta) override {
        Uniform();
    }

    int GetUniform(const std::string& uniform) const {
        int result = glGetUniformLocation(_program, uniform.c_str());
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            throw std::runtime_error("Vertex attribute array buffer adding failed");
        }

        return result;
    }

    void UniformMatrix(const std::string &uniformType, glm::mat4 data) const {
        const GLint glLoc = glGetUniformLocation(_program, uniformType.c_str());
        glUniformMatrix4fv(glLoc, 1, GL_FALSE, glm::value_ptr(data));
    }

    void UniformVector(const std::string &uniformType, const glm::vec3 &data) const {
        const GLint glLoc = glGetUniformLocation(_program, uniformType.c_str());
        glUniform3fv(glLoc, 1, glm::value_ptr(data));
    }

    static void UniformMatrix(const int &uniformPos, glm::mat4 data) {
        glUniformMatrix4fv(uniformPos, 1, GL_FALSE, glm::value_ptr(data));
    }

    static void UniformVector(const int &uniformPos, const glm::vec3 &data) {
        glUniform3fv(uniformPos, 1, glm::value_ptr(data));
    }

    void Uniform() {
        for (auto &[pos, uniform]: std::ranges::views::values(_uniforms)) {
            uniform->Uniform(pos);
        }
    }

    size_t AddUniform(const std::string &uniformName, IUniform *uniform) {
        std::pair pa = {GetUniform(uniformName), uniform};
        _uniforms.emplace(curUniformId, pa);
        return curUniformId++;
    }

    GLuint _program;
private:

    std::unordered_map<
        size_t,
        std::pair<
            int,
            IUniform *>
    > _uniforms;

    size_t curUniformId = 0;
};


#endif //SHADERPROGRAM_HPP
