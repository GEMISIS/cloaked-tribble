#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Object.h"
#include <GLFW/glfw3.h>

class Camera : public Object
{
public:
	Camera();
	Camera(GLFWwindow* window);
	bool Init(GLFWwindow* window);
	bool Update();
	bool Draw();
	bool Destroy();
private:
	GLFWwindow* window;
};

#endif