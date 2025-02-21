#include <iostream>
#define GLFW_INCLUDE_NONE
#include <glm/ext.hpp>

#include <LibFacade.hpp>
#include <Drawables/DrawableObject.h>
#include <Shaders/ShaderProcessor.hpp>
#include <Window.h>
#include <Camera.h>
#include <loader.hpp>
#include <Events/InputHandler.hpp>
#include <Events/EventHandler.hpp>

#include "assets/testTriangle.h"
#include "Buffers/ShaderStorageBuffer.hpp"
#include "Shaders/ShaderBuilder.hpp"
#include "Utils/ObjParser.hpp"

using namespace glm;

int main() {
    InitLib();

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

    auto window = Window(800, 600, "title", 70.0f);
    auto camera = Camera(glm::vec3(0.0f, 0.1f, 1.0f));
    window.SetClearColor(0.4, 0.4, 0.4, 1);

    window.Open();
    InputHandler handler = window.InitWindowInputHandler();
    EventHandler eventHandler(&window);

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
    objParser.parseOBJFile(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\Glaceon.obj)");

    std::vector<float> bVertices = objParser.getVertices();

    std::vector<unsigned int> indices = objParser.getFaces();

    VertexAttributesBuffer vao;
    vao.AddAttribute(0, new ArrayBuffer(bVertices), 3).AddElementBuffer(new ElementBuffer(indices));

    DrawableObject obj;
    obj.SetVAO(vao);

    objParser.parseOBJFile(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\floor.obj)");

    bVertices = objParser.getVertices();

    indices = objParser.getFaces();

    VertexAttributesBuffer vao1;
    vao1.AddAttribute(0, new ArrayBuffer(bVertices), 3).AddElementBuffer(new ElementBuffer(indices));

    DrawableObject obj2;
    obj2.SetVAO(vao1);

    std::vector<glm::mat4> models = { obj.GetModel(), obj2.GetModel() };
    ShaderStorageBuffer modelBuffer(models);
    modelBuffer.BindBufferLayout(1);

    eventHandler.SetMovable(&camera);

    renderer.AddDrawable(&obj);
    renderer.AddDrawable(&obj2);
    obj.Scale(0.01f);

    vec3 lightPos = vec3(0.0f, 0.3f, 0.3f);
    int iter = 0;
    while (!window.ShouldClose) {
        shader.UniformMatrix("vp",
                                window.GetProjectionMatrix() * camera.GetViewMatrix());
        shader.UniformVector("screenSize", glm::vec3(window.GetWidth(), window.GetHeight(), 0.0f));
        shader.UniformMatrix("p", window.GetProjectionMatrix());
        shader.UniformMatrix("v", camera.GetViewMatrix());

        if (iter++ % 1000 < 500) {
           lightPos.x -= 0.01f;
        }
        else {
            lightPos.x += 0.01f;
        }

        shader.UniformVector("worldLightPos", lightPos);


        modelBuffer.ChangeBufferElement(obj.GetModel(), 0);

        window.ClearScreen();
        eventHandler.HandleInputs();
        shader.UniformMatrix("model", obj2.GetModel());
        obj2.Draw();
        shader.UniformMatrix("model", obj.GetModel());
        obj.Draw();
        window.Update();
    }

    return 0;
}
