#include "MainGame.h"
#include <GL/GLU.h>

MainGame::MainGame() : Gamestate()
{
}

void MainGame::initializeLogic()
{
	rotation = 0.0f;
}

void MainGame::initializeGraphics()
{
}

bool MainGame::updateLogic()
{
	if(this->rotation < 360.0f)
	{
		this->rotation += 1.0f;
	}
	else
	{
		this->rotation = 0.0f;
	}
	return true;
}

bool MainGame::updateGraphics()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	{
		glTranslatef(-1.5f, 0.0f, -6.0f);
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glBegin(GL_TRIANGLES);
		{
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 0.0f);
		}
		glEnd();
	}
	glPopMatrix();

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

