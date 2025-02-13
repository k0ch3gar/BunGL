#include <iostream>
#define GLFW_INCLUDE_NONE
#include <glm/ext.hpp>

#include <LibFacade.hpp>
#include <Drawables/DrawableObject.h>
#include <Shaders/ShaderProcessor.hpp>
#include <Window.h>
#include <Camera.h>
#include <Events/InputHandler.hpp>
#include <Events/EventHandler.hpp>

#include "assets/testTriangle.h"
#include "Shaders/ShaderBuilder.hpp"
#include "Utils/ObjParser.hpp"

using namespace glm;

int main() {
    InitLib();

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

    auto window = Window(800, 600, "title", 70.0f);
    auto camera = Camera(glm::vec3(0.0f, 0.1f, 2.0f));
    window.SetClearColor(0.4, 0.4, 0.4, 1);

    window.Open();
    InputHandler handler = window.InitWindowInputHandler();
    EventHandler eventHandler(&handler);

    Renderer renderer;
    ShaderBuilder shaderBuilder;
    ShaderProgram shader =
        shaderBuilder
        .AttachGeometryShader(geometryShaderSource)
        .AttachVertexShader(vertexShaderSource)
        .AttachFragmentShader(fragmentShaderSource)
        .Build();

    shader.UseProgram();
    ObjParser objParser;
    objParser.parseOBJFile(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\duck.obj)");

    std::vector<float> bVertices = objParser.getVertices();

    std::vector<unsigned int> indices = objParser.getFaces();

    DrawableObject obj(bVertices, indices);
    eventHandler.SetMovable(&camera);

    obj.Scale(0.01f);
    renderer.AddDrawable(&obj);

    while (!window.ShouldClose) {
        shader.UniformMatrix(ShaderEnum::MVP,
                                window.GetProjectionMatrix() * camera.GetViewMatrix() * obj.GetModel());
        shader.UniformVector(ShaderEnum::CameraNormal, camera.GetViewMatrix() * glm::vec4(0.0f, 0.0f, -1.0f, 1.0f));

        window.ClearScreen();
        renderer.Render();
        eventHandler.HandleInputs();
        window.Update();
    }

    return 0;
}
