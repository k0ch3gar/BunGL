#include "Window.h"

#include <iostream>
#include <LibFacade.hpp>

#include "glm/ext/matrix_clip_space.hpp"

Window::Window(int width, int height, const char *title, float fov) {
    _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    _clearColor = glm::vec4(0, 0, 0, 1);
    _width = width;
    _height = height;
    _fov = fov;
    _projection = glm::perspective(fov, (float)width/(float)height, 0.01f, 100.0f);
}

Window::~Window() {
    glfwDestroyWindow(_window);
}

void Window::Open() const {
    glfwMakeContextCurrent(_window);
    InitRender();
}

void Window::ClearScreen() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(_clearColor.r, _clearColor.g, _clearColor.b, _clearColor.a);
}

void Window::Update() {
    glfwSwapBuffers(_window);
    if (glfwWindowShouldClose(_window)) ShouldClose = true;
}

InputHandler Window::InitWindowInputHandler() {
    return {_window};
}

void Window::SetClearColor(float r, float g, float b, float a) {
    _clearColor.r = r;
    _clearColor.g = g;
    _clearColor.b = b;
    _clearColor.a = a;
}

glm::mat4 Window::GetProjectionMatrix() const {
    return _projection;
}

void Window::SetNewWindowSize(int width, int height) {
    _width = width;
    _height = height;
    if (_height < 10 || _width < 10) return;
    _projection = glm::perspective(_fov, (float)width/(float)height, 0.01f, 100.0f);
    glViewport(0, 0, width, height);
}

void Window::SwitchCursorMode() {
    glfwSetInputMode(_window, GLFW_CURSOR, _cursorVisible ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
    _cursorVisible = !_cursorVisible;
}

bool Window::IsCursorVisible() const {
    return _cursorVisible;
}
