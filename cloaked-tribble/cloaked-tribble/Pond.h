#ifndef _POND_H_
#define _POND_H_
/*
* Pond is a virtual water model of the game's surface
* Movements and actions will create ripples in the pond,
* which are managed by moving waves, non-visible "objects."
* the waves will be managed by the objectmanager and die
* upon losing all magnitude. Pond merely handles the math
* behind the generation
*/
#include "Wave.h"
#include "ActionEvent.h"
#include "ObjectManager.h"
class Pond
{
public:
	Pond(ObjectManager* om);
	bool Init(ObjectManager* om);
	bool Destroy();
	bool catchEvent(ActionEvent* e);
	bool update();
protected:
	ObjectManager* manager;
};


#endif
