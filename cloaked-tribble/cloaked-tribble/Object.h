#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <GL/glew.h>
#include "types.h"

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
protected:
	Vertex position;
};

#endif