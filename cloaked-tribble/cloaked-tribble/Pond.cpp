#include "Pond.h"
#include "types.h"
#include "ActionEvent.h"
#include "Wave.h"
#include "ObjectManager.h"
Pond::Pond(ObjectManager* om)
{
	//initialize the pond,
	Init(om);
}

bool Pond::Init(ObjectManager* om)
{
	//initialize or reinitialize the pond
	manager = om;
	return true;

}

bool Pond::Destroy()
{
	return false;
}

bool Pond::catchEvent(ActionEvent* e)
{
	Vertex* vector = &e->getObject()->velocity;
	//movements are handled here.
	//stepping does 2 things:
	//1. ring ripple, an inlarging ring for detection
	//2. Spreading tail
	//for now we'll only implement the ring for POC
	Wave* influence = new Wave(&(e->getObject()->position),vector);
	manager->addObject(influence);
	return true;
}
