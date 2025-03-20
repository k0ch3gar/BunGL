#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <ranges>

#include <utility>

#include "Window.h"

class EventHandler : public Updatable {
public:
    explicit EventHandler();

    void Update(double delta) override {
        for (const auto &[f, s] : std::views::values(_events)) {
            if (f()) s();
        }
    }

    bool RemoveEvent(const size_t eventId) {
        if (!_events.contains(eventId)) return false;
        _events.erase(eventId);

        return true;
    }

    size_t AddEvent(const std::function<bool()>& event, const std::function<void()>& func) {
        _events.emplace(_currentId++, std::pair(event, func));
        return _events.size() - 1;
    }

private:
    std::unordered_map<
        size_t,
        std::pair<
            std::function<bool()>,
            std::function<void()>
        >
    > _events;

    size_t _currentId = 0;
};

inline EventHandler::EventHandler() {
}

#endif //EVENTHANDLER_HPP
