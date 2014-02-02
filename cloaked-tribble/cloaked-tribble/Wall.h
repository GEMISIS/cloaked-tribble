#ifndef _WALL_H_
#define _WALL_H_

#include "Object.h"

class Wall : public Object
{
public:
	bool Init();
	bool Update();
	bool Draw();
	bool Destroy();
private:
	unsigned int verticesHandle;
};

#endif