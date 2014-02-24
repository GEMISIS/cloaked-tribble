#include "camera.h"

#include <math.h>
#include <iostream>
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
	//collisionRadius=5;
	this->window = window;

	// Setup the initial position and rotation.
	this->position.x = 0.0f;
	this->position.y = 0.0f;
	this->position.z = 10.0f;
	this->rotation.yaw = 0.0f;
	this->rotation.pitch = 0.0f;
	this->rotation.roll = 0.0f;
	this->velocity.x=0;
	this->velocity.y=0;
	this->velocity.z=0;
	this->xOld=0;
	this->yOld=0;
	this->collisionRadius=4;
	this->wkeypressed=false;
	this->akeypressed=false;
	this->skeypressed=false;
	this->dkeypressed=false;
	return true;
}
bool Camera::Update()
{
	if(glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		this->velocity.x = sin(M_PI * this->rotation.yaw / 180.0f) * 0.01f;
		this->velocity.z = -cos(M_PI * this->rotation.yaw / 180.0f) * 0.01f;
		wkeypressed=true;
	}

	if(glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS)
	{
		this->velocity.x = -sin(M_PI * (this->rotation.yaw + 90.0f) / 180.0f) * 0.01f;
		this->velocity.z = cos(M_PI * (this->rotation.yaw + 90.0f) / 180.0f) * 0.01f;
		akeypressed=true;
	}

	if(glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS)
	{
		this->velocity.x = -sin(M_PI * this->rotation.yaw / 180.0f) * 0.01f;
		this->velocity.z = cos(M_PI * this->rotation.yaw / 180.0f) * 0.01f;
		skeypressed=true;
	}

	if(glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS)
	{
		this->velocity.x = sin(M_PI * (this->rotation.yaw + 90.0f) / 180.0f) * 0.01f;
		this->velocity.z = -cos(M_PI * (this->rotation.yaw + 90.0f) / 180.0f) * 0.01f;
		dkeypressed=true;
	}
	if(glfwGetKey(this->window, GLFW_KEY_W) == GLFW_RELEASE)
	{
		if(!keypressed){
			this->velocity.x=0;
			this->velocity.z=0;
		}
		wkeypressed=false;
	}
	if(glfwGetKey(this->window, GLFW_KEY_A) == GLFW_RELEASE)
	{
		if(!keypressed){
			this->velocity.x=0;
			this->velocity.z=0;
		}
		akeypressed=false;
	}
	if(glfwGetKey(this->window, GLFW_KEY_S) == GLFW_RELEASE)
	{
		if(!keypressed){
			this->velocity.x=0;
			this->velocity.z=0;
		}
		skeypressed=false;
	}
	if(glfwGetKey(this->window, GLFW_KEY_D) == GLFW_RELEASE)
	{
		if(!keypressed){
			this->velocity.x=0;
			this->velocity.z=0;
		}
		dkeypressed=false;
	}
	if(wkeypressed||akeypressed||skeypressed||dkeypressed)
		keypressed=true;
	else
		keypressed=false;
	if(glfwGetKey(this->window, GLFW_KEY_LEFT))
	{
		this->rotation.yaw -= 0.1f;
	}
	if(glfwGetKey(this->window, GLFW_KEY_RIGHT))
	{
		this->rotation.yaw += 0.1f;
	}
	if(this->rotation.yaw > 360.0f || this->rotation.yaw < -360.0f)
	{
		this->rotation.yaw = 0.0f;
	}
	mouseMove();
	//glutPassiveMotionFunc(mouseMove);
	//std::cout<<"Test"<<std::endl;
	Draw();
	return true;
}
bool Camera::Draw()
{
	glRotatef(rotation.pitch, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation.yaw, 0.0f, 1.0f, 0.0f);
	glRotatef(rotation.roll, 0.0f, 0.0f, 1.0f);
	
	glTranslatef(-position.x, -position.y, -position.z);
	//std::cout<<"Test"<<std::endl;
	return true;
}
bool Camera::mouseMove()
{
	int winwidth;
	int winheight;
	glfwGetWindowSize(this->window,&winwidth,&winheight);
	double centerx=winwidth/2;
	double centery=winheight/2;
	double curx=0;
	double cury=0;
	glfwGetCursorPos(this->window,&curx,&cury);
	//double deltax = curx-centerx;
	//double deltay = cury - centery;
	rotation.pitch=((((int)cury)/2)%360); //2 is sensitivity
	rotation.yaw=((((int)curx)/2)%360);
	//if(rotation.pitch>45.0f)
		//rotation.pitch=90.0f;
	//if(rotation.yaw>90.0f)
	//	rotation.yaw=90.0f;
	//glfwSetCursorPos(this->window,centerx, centery);
	return true;
}
bool Camera::Destroy()
{
	return true;
}