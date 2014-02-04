#include "Pond.h"

Pond::Pond()
{
	//initialize the pond,
	this.Init();
}

bool Pond::Init()
{
	//initialize or reinitialize the pond

	return true;

}

bool Pond::Destroy()
{
	return false;
}

bool Pond::catchEvent(ActionEvent* e)
{
	Vertex* vector = *(e->getObject()->velocity);
	//movements are handled here.
	//stepping does 2 things:
	//1. ring ripple, an inlarging ring for detection
	//2. Spreading tail
	//for now we'll only implement the ring for POC
	Wave* influence = new Wave(*(e->getObject()->position),vector);
	return true;
}
