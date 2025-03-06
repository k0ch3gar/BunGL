#ifndef UNIFORMABLE_HPP
#define UNIFORMABLE_HPP
#include <string>

#include "IUniform.h"

template<typename T>
class Uniformable : public IUniform {
public:
    explicit Uniformable(T* value) : value(value) {}

    void Uniform(int uniformPos) override = 0;

protected:
    T* value;
};

#endif //UNIFORMABLE_HPP
