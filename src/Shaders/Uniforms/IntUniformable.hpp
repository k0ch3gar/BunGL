#ifndef INTUNIFORMABLE_HPP
#define INTUNIFORMABLE_HPP
#include "Uniformable.hpp"
#include "UniformManager.hpp"

class IntUniformable : public Uniformable<int> {
public:
    explicit IntUniformable(int *value) : Uniformable(value) {}

    void Uniform(int uniformPos) override {
        glUniform1iv(uniformPos, 1, value);
    }
};
#endif //INTUNIFORMABLE_HPP
