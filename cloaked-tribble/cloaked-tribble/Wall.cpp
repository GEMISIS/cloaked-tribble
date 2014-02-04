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
	// Create the vertex array handle.
	glGenVertexArrays(1, &this->verticesArrayHandle);
	glBindVertexArray(this->verticesArrayHandle);

	// Create the vertices buffer.
	glGenBuffers(1, &this->verticesBufferHandle);
	glBindBuffer(GL_ARRAY_BUFFER, this->verticesBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(wallVertices), wallVertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);

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
		glBindVertexArray(this->verticesArrayHandle);

		glTranslatef(this->position.x, this->position.y, this->position.z);
		glRotatef(this->rotation.yaw, 0.0f, 1.0f, 0.0f);
		glRotatef(this->rotation.roll, 0.0f, 0.0f, 1.0f);
		glRotatef(this->rotation.pitch, 1.0f, 0.0f, 0.0f);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	glPopMatrix();
	return true;
}
bool Wall::Destroy()
{
	return true;
}