#ifndef _ACTIONEVENT_H_
#define _ACTIONEVENT_H_
#include "Object.h"
class ActionEvent
{
public:
	ActionEvent();
	ActionEvent(Object* origin);
	Object* getObject();
protected:
	Object* source;
};
#endif