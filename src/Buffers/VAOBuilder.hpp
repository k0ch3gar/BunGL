#ifndef VAOBUILDER_HPP
#define VAOBUILDER_HPP
#include "VertexArrayBuffer.hpp"

class VAOBuilder {
public:
    VAOBuilder *WithVertices(std::vector<float>& vertices) {
        _arrayBuffer = new ArrayBuffer(vertices);
        return this;
    }

    VAOBuilder *WithElementBuffer(std::vector<uint32_t>& elementBuffer) {
        _elementBuffer = new ElementBuffer(elementBuffer);
        return this;
    }

    VertexArrayBuffer Build() {
        if (_arrayBuffer == nullptr ||
            _elementBuffer == nullptr)
            throw std::invalid_argument("VAO Buffer or ElementBuffer is null");

        return {_arrayBuffer, _elementBuffer};
    }

private:
    ArrayBuffer *_arrayBuffer = nullptr;
    ElementBuffer *_elementBuffer = nullptr;
};

#endif //VAOBUILDER_HPP
