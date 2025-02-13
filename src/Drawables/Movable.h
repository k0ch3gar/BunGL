#ifndef IMOVABLE_H
#define IMOVABLE_H

#include "glm/glm.hpp"

class Movable {
public:
    Movable() = default;

    virtual Movable& RotateX(float xRad);

    virtual Movable& RotateY(float yDegree);

    virtual Movable& RotateZ(float zRad);

    virtual Movable& Move(glm::vec3 diff);

    virtual Movable& Scale(float size);

protected:
    glm::mat4 rot = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::vec3 pos{};
};

#endif //IMOVABLE_H
