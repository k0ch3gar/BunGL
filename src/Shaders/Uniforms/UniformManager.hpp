#ifndef UNIFORMMANAGER_HPP
#define UNIFORMMANAGER_HPP
#include <string>
#include <unordered_map>
#include <Shaders/ShaderProgram.hpp>

#include "IUniform.h"

class UniformManager {
public:
    virtual ~UniformManager() = default;

    UniformManager& AddUniform(int uniformName, IUniform* uniform) {
        _uniforms.emplace(uniformName, uniform);
        return *this;
    }

    virtual void RegisterUniforms(ShaderProgram* shader) = 0;

    void Uniform() {
        for (auto&[uniformName, uniform] : _uniforms) {
            uniform->Uniform(uniformName);
        }
    }

private:
    std::unordered_map<int, IUniform*> _uniforms;
};

#endif //UNIFORMMANAGER_HPP
