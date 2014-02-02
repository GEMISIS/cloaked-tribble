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
	virtual bool Init()
	{
		return true;
	}
	virtual bool Destroy()
	{
		return false;
	}
	bool Update()
	{
		return true;
	}
	std::vector<Object> getObjectList()
	{
		return objectList;
	}
protected:
	std::vector<Object> objectList;

}

#endif