#include "Attachable.h"

#include <ranges>

size_t Attachable::AttachRotatable(Rotatable *attachable) {
    _rotatable.emplace(_attachableIndex, attachable);
    return _attachableIndex++;
}

size_t Attachable::AttachMovable(Movable *attachable) {
    _movable.emplace(_attachableIndex, attachable);
    return _attachableIndex++;
}

size_t Attachable::AttachScalable(Scalable *attachable) {
    _scalable.emplace(_attachableIndex, attachable);
    return _attachableIndex++;
}

void Attachable::Move(glm::vec3 offset) {
    for (auto& attachable : std::ranges::views::values(_movable)) {
        attachable->Move(offset);
    }

}

void Attachable::Rotate(float xDegree, float yDegree, float zDegree) {
    for (auto& attachable : std::ranges::views::values(_rotatable)) {
        attachable->RotateX(xDegree);
        attachable->RotateY(yDegree);
        attachable->RotateZ(zDegree);
    }

}

void Attachable::Scale(float scale) {
    for (auto& attachable : std::ranges::views::values(_scalable)) {
        attachable->Scale(scale);
    }

}
