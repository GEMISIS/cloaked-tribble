#ifndef _ACTIONEVENT_H_
#define _ACTIONEVENT_H_
#include "Object.h"
#include "ObjectManager.h"
class ActionEvent
{
public:
	ActionEvent();
	ActionEvent(Object* origin,ObjectManager* om);
	Object* getObject();
	//Object* source;
protected:
	Object* source;
	ObjectManager* manager;
	bool Act();
};
#endif