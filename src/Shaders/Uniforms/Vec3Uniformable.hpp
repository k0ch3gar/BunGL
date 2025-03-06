#ifndef VEC3UNIFORMABLE_HPP
#define VEC3UNIFORMABLE_HPP
#include "Mat4Uniformable.hpp"
#include "Uniformable.hpp"
#include "glm/vec3.hpp"

class Vec3Uniformable : public Uniformable<glm::vec3> {
public:
    explicit Vec3Uniformable(glm::vec3* value) : Uniformable(value) { }

    void Uniform(int uniformPos) override {
        glUniform3fv(uniformPos, 1, glm::value_ptr(*value));
    }
};


#endif //VEC3UNIFORMABLE_HPP
