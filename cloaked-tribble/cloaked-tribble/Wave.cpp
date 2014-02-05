#include "Wave.h"

Wave::Wave()
{
	position=0;
	velocity=0;
	collisionRadius=1;
	magnitude = 10;
}
Wave::Wave(Vertex* pos, Vertex* vel)
{
	position = pos;
	velocity = vel;
	collisionRadius=1;
	magnitude = 10;
}
bool Wave::Draw()
{
	/**
	* NOTICE: THIS METHOD IS THE WAVE UPDATE METHOD WHERE PATHING IS INCREASED
	**/
	//move for current magnitude
	collisionRadius=(collisionRadius+magnitude--)/collisionRadius; //may come back to this wave
	return true;
}