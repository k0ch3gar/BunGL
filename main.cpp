#include <iostream>
#define GLFW_INCLUDE_NONE
#include <glm/glm.hpp>

#include <LibFacade.hpp>
#include <Shaders/ShaderProcessor.hpp>
#include <Window.h>
#include <Camera.h>
#include <loader.hpp>
#include <Events/EventHandler.hpp>

#include "Buffers/ShaderStorageBuffer.hpp"
#include "Properties/BasicSceneObject.h"
#include "Scene/Scene.h"
#include "Shaders/ShaderBuilder.hpp"
#include "Utils/ObjParser.hpp"

using namespace glm;

int main() {
    Window window(800, 600, "title", 70);
    window.SetClearColor(0.4, 0.4, 0.4, 1);
    window.Open();

    InputHandler inputHandler = window.InitWindowInputHandler();
    EventHandler eventHandler;

    ShaderBuilder shaderBuilder;
    ShaderProgram shader =
            shaderBuilder
            .AttachVertexShader(vertexShaderSource)
            .AttachGeometryShader(geometryShaderSource)
            .AttachFragmentShader(fragmentShaderSource)
            .Build();

    shader.UseProgram();

    BasicSceneObject obj = bunGL::MakeDrawableFromObj(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\bnuuy.obj)" , 0);
    BasicSceneObject obj2 = bunGL::MakeDrawableFromObj(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\Glaceon.obj)" , 0);
    BasicSceneObject obj3 = bunGL::MakeDrawableFromObj(R"(C:\Users\kosti\CLionProjects\ServerOpenGLRenderer\assets\floor.obj)" , 0);
    Camera camera;
    obj2.Scale(0.01f);

    camera.RegisterUniforms(&shader);
    window.RegisterUniforms(&shader);
    obj.RegisterUniforms(&shader);
    obj2.RegisterUniforms(&shader);
    obj3.RegisterUniforms(&shader);

    Scene scene;
    scene.AddRegistry(&eventHandler);
    scene.AddRegistry(&camera);
    scene.AddRegistry(&obj);
    scene.AddRegistry(&obj2);
    scene.AddRegistry(&obj3);
    scene.RegisterUniforms(&shader);
    LightData lightData{};
    lightData.worldLightPos = vec3(-1.0, 1.0f, 0.2f);
    lightData.color = vec4(0.2f, 0.8f, 0.4f, 1.0f);
    lightData.kc = 0;
    lightData.kl = 0.1;
    lightData.kq = 0;
    lightData.lightDirection = normalize(vec3(-0.7, -0.5f, 0.7));
    lightData.lightDirection = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(-45.0f), glm::vec3(0, 1, 0)) * glm::vec4(lightData.lightDirection, 1));
    lightData.p = 10;
    lightData.coneAngle = glm::radians(10.0f);
    size_t lightIndex = scene.AddLight(lightData);
    lightData.lightDirection.x = 0.2f;
    lightData.worldLightPos = vec3(0, 0.1, 0.2f);
    lightData.color = vec4(1,0,0,1);
    scene.AddLight(lightData);

    window.AddUpdatable(&inputHandler);
    window.AddUpdatable(&shader);
    window.AddUpdatable(&scene);

    // camera.AttachMovable(&obj);
    // camera.AttachRotatable(&obj);

    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_A);}, [&](){camera.Move(vec3(-1,0,0));});
    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_D);}, [&](){camera.Move(vec3(1,0,0));});
    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_W);}, [&](){camera.Move(vec3(0,0,-1));});
    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_S);}, [&](){camera.Move(vec3(0,0,1));});
    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_SPACE);}, [&](){camera.Move(vec3(0,1,0));});
    eventHandler.AddEvent([&](){return inputHandler.isKeyPressed(GLFW_KEY_LEFT_SHIFT);}, [&](){camera.Move(vec3(0,-1,0));});
    eventHandler.AddEvent([&](){return inputHandler.isMouseButtonJustPressed(GLFW_MOUSE_BUTTON_LEFT);}, [&](){window.SwitchCursorMode();});
    eventHandler.AddEvent([&](){return !window.IsCursorVisible();}, [&]() {
        if (const vec2 offset = inputHandler.getMouseOffset(); offset.x != 0 || offset.y != 0) {
            camera.RotateX(-offset.y / 5.0f);
            camera.RotateY(-offset.x / 5.0f);
        }
    });
    eventHandler.AddEvent([&]() { return inputHandler.isWindowSizeChanged(); }, [&]() {
        window.SetNewWindowSize(inputHandler.getWindowSize().x, inputHandler.getWindowSize().y);
    });
    eventHandler.AddEvent([&](){return true;}, [&]() {
        // obj2.RotateY(1.0f);

            // lightData.lightDirection = camera.GetDirection();
            // lightData.worldLightPos = camera.GetPosition();
            scene.UpdateLight(lightIndex, lightData);
    });

    window.Join();

    return 0;
}