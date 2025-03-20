#ifndef ATTACHABLE_H
#define ATTACHABLE_H
#include "Movable.h"
#include "Rotatable.h"
#include "Scalable.h"

class Attachable {
public:
    virtual ~Attachable() = default;

    size_t AttachRotatable(Rotatable* attachable);

    size_t AttachMovable(Movable* attachable);

    size_t AttachScalable(Scalable* attachable);

    void Move(glm::vec3 offset);

    void Rotate(float xDegree, float yDegree, float zDegree);

    void Scale(float scale);

private:
    std::unordered_map<size_t, Rotatable*> _rotatable;
    std::unordered_map<size_t, Movable*> _movable;
    std::unordered_map<size_t, Scalable*> _scalable;
    size_t _attachableIndex = 0;
};



#endif //ATTACHABLE_H
