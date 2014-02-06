#ifndef _UNIFIEDMANAGER_H_
#define _UNIFIEDMANAGER_H_
#include <list>
#include "Object.h"
#include "types.h"


class UnifiedManager
{
public:
	UnifiedManager();
	bool Init();
	bool addObject(Object* input);
	bool Update();
	float sqrt(float n);
protected:
	float distance;
	Object* tmp1;
	Object* tmp2;
	Vertex* pos1;
	Vertex* pos2;
	Vertex* vel1;
	Vertex* vel2;
	std::list<Object*> objectList;
};

#endif