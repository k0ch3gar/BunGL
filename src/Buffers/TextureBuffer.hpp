#ifndef TEXTUREBUFFER_HPP
#define TEXTUREBUFFER_HPP
#include <loader.hpp>

#include "Buffer.hpp"
#include "Utils/TextureData.h"

template<GLenum TextureType>
class TextureBuffer {
public:

    void Bind() {
        glBindTexture(TextureType, _texture);
    }

    void Unbind() {
        glBindTexture(TextureType, 0);
    }

    TextureBuffer() {
        glGenTextures(1, &_texture);
    }

    TextureBuffer& SetTextureData2D(const bunGL::TextureData & textureData) {
        Bind();
        glTexImage2D(TextureType,
            0,
            textureData.internalFormat,
            textureData.width,
            textureData.height,
            0,
            textureData.format,
            GL_UNSIGNED_BYTE,
            textureData.data);
        Unbind();
        return *this;
    }

    TextureBuffer& GenMipmap2D() {
        Bind();
        glGenerateMipmap(TextureType);
        Unbind();
        return *this;
    }

    TextureBuffer& WithWrappingOptions() {
        Bind();
        glTexParameteri(TextureType, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(TextureType, GL_TEXTURE_WRAP_T, GL_REPEAT);
        Unbind();
        return *this;
    }

    TextureBuffer& WithFilteringOptions() {
        Bind();
        glTexParameteri(TextureType, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(TextureType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        Unbind();
        return *this;
    }

private:
    GLuint _texture{};
};

#endif //TEXTUREBUFFER_HPP
