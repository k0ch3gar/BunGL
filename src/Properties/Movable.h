#ifndef IMOVABLE_H
#define IMOVABLE_H

#include "glm/glm.hpp"

class Movable {
public:
    virtual ~Movable() = default;

    virtual Movable& Move(glm::vec3 diff);

    [[nodiscard]] virtual glm::vec3 GetPosition() const;

protected:
    glm::vec3 pos{};
};

#endif //IMOVABLE_H
