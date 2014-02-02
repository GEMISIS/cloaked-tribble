#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_

#include "types.h"
#include <vector>
#include "Object.h"
/*
* Class for managing all objects as produced for this game
*/

class ObjectManager
{

public:
	ObjectManager();
	bool Init();
	virtual bool Destroy()
	{
		return false;
	}
	bool Update();
	void addObject(Object* object);
	std::vector<Object*> getObjectList()
	{
		return objectList;
	}
	bool addObject(Object object);
protected:
	float distance; //for memory management
	std::vector<Object*> objectList;

};

#endif