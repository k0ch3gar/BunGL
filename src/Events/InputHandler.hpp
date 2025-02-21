#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <unordered_map>

class InputHandler {
public:
    InputHandler(GLFWwindow* window)
        : _window(window),
          _mousePos(0.0f, 0.0f),
          _lastMousePos(0.0f, 0.0f),
          _mouseOffset(0.0f, 0.0f),
          _firstMouseMove(true) {

        glfwSetWindowUserPointer(window, this);

        glfwSetKeyCallback(window, keyCallback);
        glfwSetMouseButtonCallback(window, mouseButtonCallback);
        glfwSetCursorPosCallback(window, cursorPosCallback);
        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

        double x, y;
        glfwGetCursorPos(window, &x, &y);
        _mousePos = glm::vec2(x, y);
        _lastMousePos = _mousePos;
    }

    bool isWindowSizeChanged() const {
        return _windowSizeChanged;
    }

    void prepareForEvents() {
        _previousKeys = _keys;
        _previousMouseButtons = _mouseButtons;
    }

    void update() {
        glfwPollEvents();
        _mouseOffset = _mousePos - _lastMousePos;
        _lastMousePos = _mousePos;

        if(_firstMouseMove) {
            _mouseOffset = glm::vec2(0.0f);
            _firstMouseMove = false;
        }
    }

    bool isKeyJustPressed(int key) const {
        bool current = _keys.count(key) ? _keys.at(key) : false;
        bool previous = _previousKeys.count(key) ? _previousKeys.at(key) : false;
        return current && !previous;
    }

    bool isMouseButtonJustPressed(int button) const {
        bool current = _mouseButtons.count(button) ? _mouseButtons.at(button) : false;
        bool previous = _previousMouseButtons.count(button) ? _previousMouseButtons.at(button) : false;
        return current && !previous;
    }

    void resetWindowSizeChanged() {
        _windowSizeChanged = false;
    }

    bool isKeyPressed(int key) const {
        auto it = _keys.find(key);
        return it != _keys.end() ? it->second : false;
    }

    bool isMouseButtonPressed(int button) const {
        auto it = _mouseButtons.find(button);
        return it != _mouseButtons.end() ? it->second : false;
    }

    glm::vec2 getMousePosition() const {
        return _mousePos;
    }

    glm::vec2 getWindowSize() const {
        return _windowSize;
    }

    glm::vec2 getMouseOffset() const {
        return _mouseOffset;
    }

    void setCursorCaptured(bool captured) {
        glfwSetInputMode(_window, GLFW_CURSOR,
            captured ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
    }

private:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        InputHandler* handler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if(handler) {
            handler->_keys[key] = (action != GLFW_RELEASE);
        }
    }

    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        InputHandler* handler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if(handler) {
            handler->_mouseButtons[button] = (action != GLFW_RELEASE);
        }
    }

    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
        if(auto* handler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window))) {
            handler->_mousePos.x = static_cast<float>(xpos);
            handler->_mousePos.y = static_cast<float>(ypos);

            if(handler->_firstMouseMove) {
                handler->_lastMousePos = handler->_mousePos;
                handler->_firstMouseMove = false;
            }
        }
    }

    static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
        InputHandler* handler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if(handler) {
            handler->_windowSize.x = width;
            handler->_windowSize.y = height;
            handler->_windowSizeChanged = true;
        }
    }


    GLFWwindow* _window;
    std::unordered_map<int, bool> _keys;
    std::unordered_map<int, bool> _previousKeys;
    std::unordered_map<int, bool> _mouseButtons;
    std::unordered_map<int, bool> _previousMouseButtons;

    glm::vec2 _mousePos;
    glm::vec2 _lastMousePos;
    glm::vec2 _mouseOffset;
    glm::vec2 _windowSize;

    bool _windowSizeChanged;
    bool _firstMouseMove;
};

#endif
