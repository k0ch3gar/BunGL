#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <Drawables/Movable.h>

#include "Window.h"

class EventHandler {
public:
    explicit EventHandler(Window* window) : _window(window), _inputHandler(window->InitWindowInputHandler()), _movable(nullptr) { }

    void HandleInputs() {
        _inputHandler.prepareForEvents();
        _inputHandler.update();
        glfwPollEvents();

        if (_inputHandler.isKeyPressed(GLFW_KEY_A)) {
            _movable->Move(glm::vec3(-0.1f * _speed, 0, 0));
        }

        if (_inputHandler.isKeyPressed(GLFW_KEY_D)) {
            _movable->Move(glm::vec3(0.1f * _speed, 0, 0));
        }

        if (_inputHandler.isKeyPressed(GLFW_KEY_S)) {
            _movable->Move(glm::vec3(0, 0, 0.1f * _speed));
        }

        if (_inputHandler.isKeyPressed(GLFW_KEY_W)) {
            _movable->Move(glm::vec3(0, 0, -0.1f * _speed));
        }

        if (_inputHandler.isKeyPressed(GLFW_KEY_Q)) {
            if (_inputHandler.isKeyPressed(GLFW_KEY_LEFT_SHIFT))
                _movable->RotateY(-1.0f);
            else
                _movable->RotateY(1.0f);
        }

        if (_inputHandler.isKeyPressed(GLFW_KEY_E)) {
            if (_inputHandler.isKeyPressed(GLFW_KEY_LEFT_SHIFT))
                _movable->RotateX(1.0f);
            else
                _movable->RotateX(-1.0f);
        }

        glm::vec2 offset = _inputHandler.getMouseOffset();
        if (!_window->IsCursorVisible())
        if (offset.x != 0 || offset.y != 0) {
            _movable->RotateX(-offset.y / 5.0f);
            _movable->RotateY(-offset.x / 5.0f);
        }


        if (_inputHandler.isWindowSizeChanged()) {
            _inputHandler.resetWindowSizeChanged();
            auto newSize = _inputHandler.getWindowSize();
            _window->SetNewWindowSize(newSize.x, newSize.y);
        }

        if (_inputHandler.isMouseButtonJustPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            _window->SwitchCursorMode();
        }
    }

    EventHandler* SetMovable(Movable* movable) {
        _movable = movable;
        return this;
    }

private:
    InputHandler _inputHandler;
    Movable* _movable;
    Window* _window;
    double _speed = 0.05f;
};

#endif //EVENTHANDLER_HPP
