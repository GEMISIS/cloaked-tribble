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
	bool mouseMove();
	//void calculateCameraMovement();
private:
	GLFWwindow* window;
	int xOld;
	int yOld;
	bool wkeypressed;
	bool akeypressed;
	bool skeypressed;
	bool dkeypressed;
	bool keypressed;
};

#endif