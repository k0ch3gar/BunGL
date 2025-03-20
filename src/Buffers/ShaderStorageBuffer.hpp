#ifndef SHADERSTORAGEBUFFER_HPP
#define SHADERSTORAGEBUFFER_HPP
#include <iostream>
#include <queue>

#include "Buffer.hpp"
#include "glm/glm.hpp"
#include <ranges>

template<typename T>
class ShaderStorageBuffer : public Buffer<GL_SHADER_STORAGE_BUFFER, T> {
public:
    explicit ShaderStorageBuffer() {
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }

    }

    int Append(const T value) {
        _data.emplace(_nextId++, value);
        std::vector<T> temp(std::ranges::views::values(_data).begin(), std::ranges::views::values(_data).end());
        this->template Fill<GL_DYNAMIC_DRAW>(temp);

        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }

        return _nextId - 1;
    }

    void Remove(int index) {
        if (!_data.contains(index)) throw std::out_of_range("Buffer index out of range");
        _data.erase(index);

        std::vector<T> temp(std::ranges::views::values(_data).begin(), std::ranges::views::values(_data).end());
        this->template Fill<GL_DYNAMIC_DRAW>(temp);

        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error: " << error << std::endl;
        }
    }

    T Get(int index) {
        return _data.at(index);
    }

private:
    std::unordered_map<int, T> _data;
    int _nextId = 0;
};

#endif //SHADERSTORAGEBUFFER_HPP
