#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <GL/glew.h>
#include "types.h"

/**
 * An object class to be extended for new objects.
 */
class Object
{
public:
	virtual bool Init()
	{
		return false;
	}
	virtual bool Update()
	{
		return false;
	}
	virtual bool Draw()
	{
		return false;
	}
	virtual bool Destroy()
	{
		return false;
	}
	virtual float getCollisionRadius()
	{
		return collisionRadius;
	}
	virtual Vertex getPosition()
	{
		return position;
	}
	virtual Rotation getRotation()
	{
		return rotation;
	}
	virtual Vertex getVelocity()
	{
		return velocity;
	}
	virtual int indentifier()
	{
		return type;
	}
public:
	float collisionRadius;
	Vertex position;
	Rotation rotation;
	Vertex velocity;
	int type;
	char id[256];
};

#endif