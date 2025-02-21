#ifndef VAOBUILDER_HPP
#define VAOBUILDER_HPP
#include "VertexAttributesBuffer.hpp"

class VAOBuilder {
public:
    VAOBuilder& WithVertices(std::vector<float>& vertices) {
        _arrayBuffer = new ArrayBuffer(vertices);
        return *this;
    }

    VAOBuilder& WithTextures(std::vector<float>& textures) {
        _textureBuffer = new ArrayBuffer(textures);
        return *this;
    }

    VAOBuilder& WithElementBuffer(std::vector<uint32_t>& elementBuffer) {
        _elementBuffer = new ElementBuffer(elementBuffer);
        return *this;
    }

    VertexAttributesBuffer Build() {
        if (_arrayBuffer == nullptr ||
            _elementBuffer == nullptr)
            throw std::invalid_argument("VAO Buffer or ElementBuffer is null");

        VertexAttributesBuffer VAO;
        VAO.AddAttribute(0, _arrayBuffer, 3).AddElementBuffer(_elementBuffer);

        return VAO;
    }

private:
    ArrayBuffer *_arrayBuffer = nullptr;
    ArrayBuffer *_textureBuffer = nullptr;
    ElementBuffer *_elementBuffer = nullptr;
};

#endif //VAOBUILDER_HPP
