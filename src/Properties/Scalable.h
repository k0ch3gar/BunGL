#ifndef SCALABLE_H
#define SCALABLE_H
#include "glm/glm.hpp"
#include "glm/ext/matrix_transform.hpp"

class Scalable {
public:
    virtual ~Scalable() = default;

    virtual Scalable& Scale(float size);

private:
    glm::mat4 scale = glm::mat4(1.0f);
};



#endif //SCALABLE_H
