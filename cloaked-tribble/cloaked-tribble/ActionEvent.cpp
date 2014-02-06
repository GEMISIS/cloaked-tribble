#include "ActionEvent.h"
#include "Object.h"
#include "Wave.h"
ActionEvent::ActionEvent()
{
	source = 0;
}
ActionEvent::ActionEvent(Object* origin, ObjectManager* om)
{
	source = origin;
	manager = om;
	Act();
}
Object* ActionEvent::getObject()
{
	return source;
}
bool ActionEvent::Act()
{
	switch(source->type)
	{
	default:
		manager->addObject(new Wave(&source->position,&source->velocity));
		break;


	}
	return true;
}