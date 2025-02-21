#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <vector>
#include <glad/glad.h>

template<GLenum usage>
concept drawType = requires (GLenum a) {
    a == GL_STATIC_DRAW;
    a == GL_DYNAMIC_DRAW;
};

template<GLenum BufferType, typename T>
class Buffer {
public:

    explicit Buffer() {
        glGenBuffers(1, &_buffer);
    }

    [[nodiscard]] size_t Size() const {
        return _size;
    }

    ~Buffer() {
        glDeleteBuffers(1, &_buffer);
    }

    void Bind() const {
        glBindBuffer(BufferType, _buffer);
    }

    void BindBufferLayout(int layout) {
        Bind();
        glBindBufferBase(BufferType, layout, _buffer);
        Unbind();
    }

    void ChangeBufferElement(T data, size_t offset) {
        Bind();
        glBufferSubData(BufferType, offset * sizeof(T), sizeof(T), &data);
        Unbind();
    }

    void Unbind() {
        glBindBuffer(BufferType, 0);
    }

    template<GLenum drawingType> requires drawType<drawingType>
    void Fill(std::vector<T>& data) {
        Bind();
        glBufferData(BufferType, data.size() * sizeof(T), data.data(), drawingType);
        _size = data.size();
        Unbind();
    }

private:
    uint32_t _buffer{};
    size_t _size{};
};

#endif //BUFFER_HPP
