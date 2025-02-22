#ifndef WINDOW_H
#define WINDOW_H

#include <chrono>
#include <list>

#include "Events/InputHandler.hpp"

#include "Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Updatable.h"
#include "glm/glm.hpp"

class Window {
public:
    Window(int width, int height, const char *title, float fov);

    ~Window();

    void Open();

    void Close();

    void ClearScreen() const;

    void Update();

    InputHandler InitWindowInputHandler();

    void SetClearColor(float r, float g, float b, float a);

    [[nodiscard]] glm::mat4 GetProjectionMatrix() const;

    bool ShouldClose = false;

    [[nodiscard]] int GetWidth() const { return _width; }

    [[nodiscard]] int GetHeight() const { return _height; }

    void SetNewWindowSize(int width, int height);

    void SwitchCursorMode();

    [[nodiscard]] bool IsCursorVisible() const;

    Window& AddUpdatable(Updatable& updatable);

private:
    GLFWwindow* _window = nullptr;

    glm::vec4 _clearColor{};
    glm::mat4 _projection{};

    std::list<Updatable&> _registries;

    float _fov;

    int _width;
    int _height;

    bool _cursorVisible = true;
    bool _shouldClose = false;
    bool _firstFrame = true;

    double _delta = 0.0f;

    std::chrono::time_point<std::chrono::high_resolution_clock> _previousTime;
};



#endif //WINDOW_H
