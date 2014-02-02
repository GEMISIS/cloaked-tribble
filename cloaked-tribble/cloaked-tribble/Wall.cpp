#include "Wall.h"

static const GLfloat wallVertices[] = {
    -1.0f, -1.0f, -0.5f,
    -1.0f, -1.0f,  0.5f,
    -1.0f,  1.0f,  0.5f,
     1.0f,  1.0f, -0.5f,
    -1.0f, -1.0f, -0.5f,
    -1.0f,  1.0f, -0.5f,
     1.0f, -1.0f,  0.5f,
    -1.0f, -1.0f, -0.5f,
     1.0f, -1.0f, -0.5f,
     1.0f,  1.0f, -0.5f,
     1.0f, -1.0f, -0.5f,
    -1.0f, -1.0f, -0.5f,
    -1.0f, -1.0f, -0.5f,
    -1.0f,  1.0f,  0.5f,
    -1.0f,  1.0f, -0.5f,
     1.0f, -1.0f,  0.5f,
    -1.0f, -1.0f,  0.5f,
    -1.0f, -1.0f, -0.5f,
    -1.0f,  1.0f,  0.5f,
    -1.0f, -1.0f,  0.5f,
     1.0f, -1.0f,  0.5f,
     1.0f,  1.0f,  0.5f,
     1.0f, -1.0f, -0.5f,
     1.0f,  1.0f, -0.5f,
     1.0f, -1.0f, -0.5f,
     1.0f,  1.0f,  0.5f,
     1.0f, -1.0f,  0.5f,
     1.0f,  1.0f,  0.5f,
     1.0f,  1.0f, -0.5f,
    -1.0f,  1.0f, -0.5f,
     1.0f,  1.0f,  0.5f,
    -1.0f,  1.0f, -0.5f,
    -1.0f,  1.0f,  0.5f,
     1.0f,  1.0f,  0.5f,
    -1.0f,  1.0f,  0.5f,
     1.0f, -1.0f,  0.5f
};

bool Wall::Init()
{
	// Create the vertices buffer.
	glGenBuffers(1, &this->verticesHandle);
	glBindBuffer(GL_ARRAY_BUFFER, this->verticesHandle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(wallVertices), wallVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Setup the initial position and rotation.
	this->position.x = 0.0f;
	this->position.y = 0.0f;
	this->position.z = 0.0f;

	this->rotation.yaw = 0.0f;
	this->rotation.pitch = 0.0f;
	this->rotation.roll = 0.0f;

	return true;
}
bool Wall::Update()
{
	return true;
}
bool Wall::Draw()
{
	glPushMatrix();
	{
		// Enable the vertices and draw them.
		glEnableClientState(GL_VERTEX_ARRAY);
		glBindBuffer(GL_ARRAY_BUFFER, this->verticesHandle);
		glVertexPointer(3, GL_FLOAT, 0, 0);

		glTranslatef(this->position.x, this->position.y, this->position.z);
		glRotatef(this->rotation.yaw, 0.0f, 1.0f, 0.0f);
		glRotatef(this->rotation.roll, 0.0f, 0.0f, 1.0f);
		glRotatef(this->rotation.pitch, 1.0f, 0.0f, 0.0f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glDisableClientState(GL_VERTEX_ARRAY);
	}
	glPopMatrix();
	return true;
}
bool Wall::Destroy()
{
	return true;
}