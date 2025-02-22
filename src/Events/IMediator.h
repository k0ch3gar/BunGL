#ifndef IMEDIATOR_H
#define IMEDIATOR_H
#include <string>

class IMediator {
public:
    virtual ~IMediator() = default;

    virtual void Notify(const std::string& sender, const std::string& event) = 0;
};

#endif //IMEDIATOR_H
