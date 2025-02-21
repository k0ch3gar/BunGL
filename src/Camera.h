#ifndef CAMERA_H
#define CAMERA_H
#include "Properties/Movable.h"
#include "glm/glm.hpp"

class Camera : public Movable {
public:
   explicit Camera(
      glm::vec3 position = glm::vec3(0, 0, 0),
      glm::vec3 up = glm::vec3(0, 1, 0),
      glm::vec3 direction = glm::vec3(0, 0, -1));


   [[nodiscard]] glm::mat4 GetViewMatrix();

   Movable& Move(glm::vec3 diff) override;

   Movable& RotateX(float xDegree) override;

   Movable& RotateY(float yDegree) override;


private:
   glm::vec3 _up;
   glm::vec3  _right;
   glm::vec3 _direction;

   float pitch;
};


#endif //CAMERA_H
