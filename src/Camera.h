#ifndef CAMERA_H
#define CAMERA_H

#include "Updatable.h"
#include "Properties/Movable.h"
#include "glm/glm.hpp"
#include "Properties/Rotatable.h"
#include "Shaders/Uniforms/IUniform.h"
#include "Shaders/Uniforms/UniformManager.hpp"

class Camera : public Movable, public Rotatable, public UniformManager, public Updatable {
public:
   explicit Camera(
      glm::vec3 position = glm::vec3(0, 0, 0),
      glm::vec3 up = glm::vec3(0, 1, 0),
      glm::vec3 direction = glm::vec3(0, 0, -1));

   void Update(double delta) override;

   void RegisterUniforms(ShaderProgram *shader) override;

   [[nodiscard]] glm::mat4 GetViewMatrix() const;

   Camera& Move(glm::vec3 diff) override;

   Camera& RotateX(float xDegree) override;

   Camera& RotateY(float yDegree) override;

private:
   glm::vec3 _up{};
   glm::vec3  _right{};
   glm::vec3 _direction{};

   glm::mat4 _view{};

   float pitch;
};


#endif //CAMERA_H
