#include "MainGame.h"
#include "Wall.h"
#include <GL/GLU.h>

	Wall wall;
MainGame::MainGame() : Gamestate()
{
	this->objectManager = new ObjectManager();

	wall.Init();
	this->objectManager->addObject(&wall);
}

void MainGame::initializeLogic()
{
	wall.rotation.yaw = 0.0f;
	wall.rotation.pitch = 0.0f;
	wall.position.x = -1.5f;
	wall.position.y = 0.0f;
	wall.position.z = -6.0f;
	this->objectManager->Init();
}

void MainGame::initializeGraphics()
{
}

bool MainGame::updateLogic()
{
	if(wall.rotation.yaw < 360.0f)
	{
		wall.rotation.yaw += 0.1f;
	}
	else
	{
		wall.rotation.yaw = 0.0f;
	}
	if(wall.rotation.pitch < 360.0f)
	{
		wall.rotation.pitch += 0.1f;
	}
	else
	{
		wall.rotation.pitch = 0.0f;
	}
	return true;
}

bool MainGame::updateGraphics()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

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

