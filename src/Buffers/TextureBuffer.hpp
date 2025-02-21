#ifndef TEXTUREBUFFER_HPP
#define TEXTUREBUFFER_HPP
#include <loader.hpp>

#include "Buffer.hpp"

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

    TextureBuffer& SetTextureData2D(const stbl::ImageData& imageData) {
        Bind();
        glTexImage2D(TextureType,
            0,
            imageData.format,
            imageData.width,
            imageData.height,
            0,
            imageData.format,
            GL_UNSIGNED_BYTE,
            imageData.image);
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
