#include "MainGame.h"
#include <GL/GLU.h>

Wall wall;
Wall wall2;

MainGame::MainGame(GLFWwindow* window) : Gamestate(window)
{
	objectManager.Init();

	wall.Init();
	wall2.Init();
	camera.Init(this->window);
	objectManager.addObject(&camera);
	objectManager.addObject(&wall);
	objectManager.addObject(&wall2);

	
}

void MainGame::initializeLogic()
{
	wall.rotation.yaw = 0.0;
	wall.rotation.pitch = 0.0;
	wall.position.x = -2.5;
	wall.position.y = 0.0;
	wall.position.z = -6.0;
	wall.collisionRadius=1;
	wall2.rotation.yaw = 0.0;
	wall2.rotation.pitch = 0.0;
	wall2.position.x = 1.5;
	wall2.position.y = 0.0;
	wall2.position.z = -6.0;
	wall2.collisionRadius=1;
	//objectManager.Init();
	
}

void MainGame::initializeGraphics()
{
}

bool MainGame::updateLogic()
{
	//camera.Update();
	wall.rotation.yaw += 0.1f;
	wall.velocity.x=0.001f;
	return true;
}

bool MainGame::updateGraphics()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//camera.Draw();

	objectManager.Update();

	return true;
}

MainGame::~MainGame()
{
}

