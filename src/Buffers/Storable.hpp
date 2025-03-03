#ifndef STORABLE_H
#define STORABLE_H
#include "Buffer.hpp"


template<GLenum BufferType, typename T>
class Storable {
public:
    explicit Storable(Buffer<BufferType, T> &buffer)
        : _buffer(buffer) {}

    void Update(T data, size_t index) {
        _buffer.Update(data, index);
    }

private:
    Buffer<BufferType, T>& _buffer;
};



#endif //STORABLE_H
