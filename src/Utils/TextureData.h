#ifndef TEXTUREDATA_H
#define TEXTUREDATA_H

#include <GLFW/glfw3.h>

namespace bunGL {
    struct TextureData {
        int mipmapLevel;
        int internalFormat;
        int width;
        int height;
        int border;
        GLenum format;
        GLenum type;
        void* data;
    };
}

#endif //TEXTUREDATA_H
