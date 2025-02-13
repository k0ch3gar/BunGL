#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <Drawables/Movable.h>

#include "Window.h"

class EventHandler {
public:
    explicit EventHandler(InputHandler* inputHandler) : _inputHandler(inputHandler), _movable(nullptr) { }

    void HandleInputs() const {
        _inputHandler->prepareForEvents();
        glfwPollEvents();

        if (_inputHandler->isKeyPressed(GLFW_KEY_A)) {
            _movable->Move(glm::vec3(-0.1f * _speed, 0, 0));
        }

        if (_inputHandler->isKeyPressed(GLFW_KEY_D)) {
            _movable->Move(glm::vec3(0.1f * _speed, 0, 0));
        }

        if (_inputHandler->isKeyPressed(GLFW_KEY_S)) {
            _movable->Move(glm::vec3(0, 0, 0.1f * _speed));
        }

        if (_inputHandler->isKeyPressed(GLFW_KEY_W)) {
            _movable->Move(glm::vec3(0, 0, -0.1f * _speed));
        }

        if (_inputHandler->isKeyPressed(GLFW_KEY_Q)) {
            _movable->RotateY(1.0f);
        }

        if (_inputHandler->isKeyPressed(GLFW_KEY_E)) {
            _movable->RotateY(-1.0f);
        }

        if (_inputHandler->isWindowSizeChanged()) {
            _inputHandler->resetWindowSizeChanged();
            auto newSize = _inputHandler->getWindowSize();
            _window->SetNewWindowSize(newSize.x, newSize.y);
        }
    }

    EventHandler* SetMovable(Movable* movable) {
        _movable = movable;
        return this;
    }

private:
    InputHandler* _inputHandler;
    Movable* _movable;
    Window* _window;
    double _speed = 0.05f;
};

#endif //EVENTHANDLER_HPP
