#ifndef _WAVE_H_
#define _WAVE_H_
#include "types.h"
#include "Object.h"


class Wave : public Object
{
public:
	Wave();
	Wave(Vertex* position,Vertex* velocity);
	bool Update();
	float magnitude;
	Vertex* position;
	Vertex* velocity;
};
#endif