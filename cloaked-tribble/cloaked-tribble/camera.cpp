#include "camera.h"

#include <math.h>

Camera::Camera()
{
}

Camera::Camera(GLFWwindow* window)
{
	this->window = window;
}

bool Camera::Init(GLFWwindow* window)
{
	type=0;
	this->window = window;

	// Setup the initial position and rotation.
	this->position.x = 0.0f;
	this->position.y = 0.0f;
	this->position.z = 0.0f;

	this->rotation.yaw = 0.0f;
	this->rotation.pitch = 0.0f;
	this->rotation.roll = 0.0f;

	return true;
}
bool Camera::Update()
{
	if(glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		this->position.x += sin(M_PI * this->rotation.yaw / 180.0f) * 0.01f;
		this->position.z -= cos(M_PI * this->rotation.yaw / 180.0f) * 0.01f;
	}
	if(glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS)
	{
		this->position.x -= sin(M_PI * (this->rotation.yaw + 90.0f) / 180.0f) * 0.01f;
		this->position.z += cos(M_PI * (this->rotation.yaw + 90.0f) / 180.0f) * 0.01f;
	}
	if(glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS)
	{
		this->position.x -= sin(M_PI * this->rotation.yaw / 180.0f) * 0.01f;
		this->position.z += cos(M_PI * this->rotation.yaw / 180.0f) * 0.01f;
	}
	if(glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS)
	{
		this->position.x += sin(M_PI * (this->rotation.yaw + 90.0f) / 180.0f) * 0.01f;
		this->position.z -= cos(M_PI * (this->rotation.yaw + 90.0f) / 180.0f) * 0.01f;
	}

	if(glfwGetKey(this->window, GLFW_KEY_LEFT))
	{
		this->rotation.yaw -= 0.1f;
	}
	if(glfwGetKey(this->window, GLFW_KEY_RIGHT))
	{
		this->rotation.yaw += 0.1f;
	}
	Draw();
	return true;
}
bool Camera::Draw()
{
	glRotatef(this->rotation.yaw, 0.0f, 1.0f, 0.0f);
	glRotatef(this->rotation.roll, 0.0f, 0.0f, 1.0f);
	glRotatef(this->rotation.pitch, 1.0f, 0.0f, 0.0f);
	glTranslatef(-this->position.x, -this->position.y, -this->position.z);

	return true;
}
bool Camera::Destroy()
{
	return true;
}