#ifndef IATTACHABLE_H
#define IATTACHABLE_H
#include "Movable.h"
#include "Rotatable.h"
#include "Scalable.h"

class IAttachable {
public:
    virtual ~IAttachable() = default;

    virtual size_t AttachRotatable(Rotatable* attachable) = 0;

    virtual size_t AttachMovable(Movable* attachable) = 0;

    virtual size_t AttachScalable(Scalable* attachable) = 0;
};

#endif //IATTACHABLE_H
