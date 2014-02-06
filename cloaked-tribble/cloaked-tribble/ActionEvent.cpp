#include "ActionEvent.h"
#include "Object.h"

ActionEvent::ActionEvent()
{
	source = 0;
}
ActionEvent::ActionEvent(Object* origin)
{
	source = origin;
}
Object* ActionEvent::getObject()
{
	return source;
}
