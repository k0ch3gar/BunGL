#ifndef MAT4UNIFORMABLE_HPP
#define MAT4UNIFORMABLE_HPP
#include <bits/locale_facets_nonio.h>
#include <glad/glad.h>

#include "Uniformable.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

class Mat4Uniformable final : public Uniformable<glm::mat4> {
public:
    explicit Mat4Uniformable(glm::mat4* value) : Uniformable(value) {}

    void Uniform(int uniformPos) override {
        glUniformMatrix4fv(uniformPos, 1, GL_FALSE, glm::value_ptr(*value));
    }
};

#endif //MAT4UNIFORMABLE_HPP
