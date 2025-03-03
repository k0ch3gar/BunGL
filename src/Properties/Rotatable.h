#ifndef ROTATABLE_H
#define ROTATABLE_H
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

class Rotatable {
public:
    virtual ~Rotatable() = default;

    virtual Rotatable& RotateX(float xDegree);

    virtual Rotatable& RotateY(float yDegree);

    virtual Rotatable& RotateZ(float zDegree);
protected:
    glm::mat4 rot = glm::mat4(1.0f);
};

#endif //ROTATABLE_H
