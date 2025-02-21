#ifndef WINDOW_H
#define WINDOW_H

#include "Events/InputHandler.hpp"

#include "Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

class Window {
public:
    Window(int width, int height, const char *title, float fov);

    ~Window();

    void Open() const;

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

private:
    GLFWwindow* _window = nullptr;

    glm::vec4 _clearColor{};
    glm::mat4 _projection{};

    float _fov;

    int _width;
    int _height;

    bool _cursorVisible = true;
};



#endif //WINDOW_H
