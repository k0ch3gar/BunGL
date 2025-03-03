#include <iostream>
#define GLFW_INCLUDE_NONE
#include <glm/ext.hpp>

#include <LibFacade.hpp>
#include <Shaders/ShaderProcessor.hpp>
#include <Window.h>
#include <Camera.h>
#include <loader.hpp>
#include <Events/EventHandler.hpp>

#include "Buffers/ShaderStorageBuffer.hpp"
#include "Scene/Scene.h"
#include "Shaders/ShaderBuilder.hpp"
#include "Utils/ObjParser.hpp"

using namespace glm;

int main() {
    //   InitLib();
    //
    //   auto window = Window(800, 600, "title", 70.0f);
    //   auto camera = Camera(glm::vec3(0.0f, 0.1f, 1.0f));
    //   window.SetClearColor(0.4, 0.4, 0.4, 1);
    //
    //   window.Open();
    //   InputHandler handler = window.InitWindowInputHandler();
    //   EventHandler eventHandler;
    //
    //   ShaderBuilder shaderBuilder;
    //   ShaderProgram shader =
    //       shaderBuilder
    //       .AttachGeometryShader(geometryShaderSource)
    //       .AttachVertexShader(vertexShaderSource)
    //       .AttachFragmentShader(fragmentShaderSource)
    //       .Build();
    //
    //   shader.UseProgram();
    //
    //   ObjParser objParser;
    //   objParser.parseOBJFile(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\Bnuuy.obj)");
    //
    //   std::vector<float> bVertices = objParser.getVertices();
    //
    //   std::vector<unsigned int> indices = objParser.getFaces();
    //
    //   VertexAttributesBuffer vao;
    //   vao.AddAttribute(0, new ArrayBuffer(bVertices), 3).AddElementBuffer(new ElementBuffer(indices));
    //
    //   DrawableObject obj;
    //   obj.SetVAO(vao);
    //
    //   objParser.parseOBJFile(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\floor.obj)");
    //
    //   bVertices = objParser.getVertices();
    //
    //   indices = objParser.getFaces();
    //
    //   VertexAttributesBuffer vao1;
    //   vao1.AddAttribute(0, new ArrayBuffer(bVertices), 3).AddElementBuffer(new ElementBuffer(indices));
    //
    //   DrawableObject obj2;
    //   obj2.SetVAO(vao1);
    //
    //   eventHandler.AddEvent([&]{ return handler.isKeyPressed(GLFW_KEY_A);}, [&]() { camera.Move(glm::vec3(-0.1f * 0.05f, 0, 0)); });
    //   eventHandler.AddEvent([&]{ return handler.isKeyPressed(GLFW_KEY_D);}, [&]() { camera.Move(glm::vec3(0.1f * 0.05f, 0, 0)); });
    //
    //   std::vector models = { obj.GetModel(), obj2.GetModel() };
    //   ShaderStorageBuffer modelBuffer(models);
    //   modelBuffer.BindBufferLayout(1);
    //
    //   eventHandler.SetMovable(&camera);
    //
    //   vec3 lightPos = vec3(0.0f, 0.3f, 0.3f);
    //   int iter = 0;
    //   while (!window.ShouldClose) {
    //       shader.UniformMatrix("vp",
    //                               window.GetProjectionMatrix() * camera.GetViewMatrix());
    //       shader.UniformVector("screenSize", glm::vec3(window.GetWidth(), window.GetHeight(), 0.0f));
    //       shader.UniformMatrix("p", window.GetProjectionMatrix());
    //       shader.UniformMatrix("v", camera.GetViewMatrix());
    //
    //       if (iter++ % 1000 < 500) {
    //          lightPos.x -= 0.01f;
    //       }
    //       else {
    //           lightPos.x += 0.01f;
    //       }
    //
    //       shader.UniformVector("worldLightPos", lightPos);
    //
    //
    //       modelBuffer.ChangeBufferElement(obj.GetModel(), 0);
    //
    //       window.ClearScreen();
    //       eventHandler.HandleInputs();
    //       shader.UniformMatrix("model", obj2.GetModel());
    //       obj2.Draw();
    //       shader.UniformMatrix("model", obj.GetModel());
    //       obj.Draw();
    //       window.Update();
    //   }
    //

    Window window(800, 600, "title", 70);
    window.SetClearColor(0.4, 0.4, 0.4, 1);
    window.Open();

    InputHandler inputHandler = window.InitWindowInputHandler();
    EventHandler eventHandler;

    ShaderBuilder shaderBuilder;
    ShaderProgram shader =
            shaderBuilder
            .AttachVertexShader(vertexShaderSource)
            .AttachFragmentShader(fragmentShaderSource)
            .Build();

    shader.UseProgram();


    Drawable obj = bunGL::MakeDrawableFromObj(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\bnuuy.obj)" , 0);
    Camera camera;

    shader.AddUniform("v", &camera);
    shader.AddUniform("p", &window);
    shader.AddUniform("model", &obj);

    Scene scene;
    scene.AddUpdatable(&eventHandler);
    scene.AddUpdatable(&camera);
    scene.AddUpdatable(&obj);

    window.AddUpdatable(&inputHandler);
    window.AddUpdatable(&shader);
    window.AddUpdatable(&scene);

    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_A);}, [&](){camera.Move(vec3(-1,0,0));});
    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_D);}, [&](){camera.Move(vec3(1,0,0));});
    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_W);}, [&](){camera.Move(vec3(0,0,-1));});
    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_S);}, [&](){camera.Move(vec3(0,0,1));});


    window.Join();

    return 0;
}