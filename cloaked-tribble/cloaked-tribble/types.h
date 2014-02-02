#ifndef _TYPES_H_
#define _TYPES_H_

struct Vertex
{
	float x, y, z;
};

struct Rotation
{
	float angle;
	Vertex axis;
};

#endif