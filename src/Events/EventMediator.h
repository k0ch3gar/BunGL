#ifndef EVENTMEDIATOR_H
#define EVENTMEDIATOR_H
#include "IMediator.h"

class EventMediator final : public IMediator {
public:
    void Notify(const std::string &sender, const std::string &event) override;
};



#endif //EVENTMEDIATOR_H
