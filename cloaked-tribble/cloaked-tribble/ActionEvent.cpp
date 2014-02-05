#include "ActionEvent.h"

ActionEvent::ActionEvent()
{
	source = 0;
}
ActionEvent::ActionEvent(Object* origin)
{
	source = origin;
}
