#include "Wave.h"

Wave::Wave()
{
	position=0;
	velocity=0;
	collisionRadius=1;
	magnitude = 10;
	type=100;
}
Wave::Wave(Vertex* pos, Vertex* vel)
{
	position = pos;
	velocity = vel;
	collisionRadius=1;
	magnitude = 10;
	type=100;
}
bool Wave::Update()
{
	/**
	* NOTICE: THIS METHOD IS THE WAVE UPDATE METHOD WHERE PATHING IS INCREASED
	**/
	//move for current magnitude
	collisionRadius=(collisionRadius+magnitude--)/collisionRadius; //may come back to this wave
	return true;
}