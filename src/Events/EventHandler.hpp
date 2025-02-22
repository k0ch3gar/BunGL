#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <map>
#include <ranges>
#include <set>
#include <Properties/Movable.h>

#include <utility>

#include "Window.h"

class EventHandler : public Updatable {
public:
    explicit EventHandler();

    void Update(double delta) override {
        for (const auto &[f, s] : std::views::values(_events)) {
            if (f()) s();
        }

/*
        glm::vec2 offset = _inputHandler->getMouseOffset();
        if (!_window->IsCursorVisible())
        if (offset.x != 0 || offset.y != 0) {
            _movable->RotateX(-offset.y / 5.0f);
            _movable->RotateY(-offset.x / 5.0f);
        }

        if (_inputHandler->isWindowSizeChanged()) {
            _inputHandler->resetWindowSizeChanged();
            auto newSize = _inputHandler->getWindowSize();
            _window->SetNewWindowSize(newSize.x, newSize.y);
        }

        if (_inputHandler->isMouseButtonJustPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            _window->SwitchCursorMode();
        }
*/
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

#endif //EVENTHANDLER_HPP
