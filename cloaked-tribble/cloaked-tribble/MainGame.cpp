#include "MainGame.h"
#include <GL/GLU.h>

Wall wall;
Wall wall2;

MainGame::MainGame(GLFWwindow* window) : Gamestate(window)
{
	this->objectManager = new ObjectManager();

	wall.Init();
	wall2.Init();
	this->objectManager->addObject(&wall);
	this->objectManager->addObject(&wall2);

	camera.Init(this->window);
}

void MainGame::initializeLogic()
{
	wall.rotation.yaw = 0.0f;
	wall.rotation.pitch = 0.0f;
	wall.position.x = -4.5f;
	wall.position.y = 0.0f;
	wall.position.z = -6.0f;
	wall.collisionRadius=1;
	wall2.rotation.yaw = 0.0f;
	wall2.rotation.pitch = 0.0f;
	wall2.position.x = 1.5f;
	wall2.position.y = 0.0f;
	wall2.position.z = -6.0f;
	wall2.collisionRadius=1;
	this->objectManager->Init();
}

void MainGame::initializeGraphics()
{
}

bool MainGame::updateLogic()
{
	camera.Update();
	wall.velocity.x=0.001f;
	return true;
}

bool MainGame::updateGraphics()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	camera.Draw();

	this->objectManager->Update();

	glPushMatrix();
	{
		glTranslatef(1.5f, 0.0f, -6.0f);
		glBegin(GL_QUADS);
		{
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
		}
		glEnd();
	}
	glPopMatrix();

	return true;
}

MainGame::~MainGame()
{
}

