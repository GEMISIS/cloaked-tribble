#ifndef _TYPES_H_
#define _TYPES_H_

typedef struct Vertex
{
	float x, y, z;
};

typedef struct Rotation
{
	float angle;
	Vertex axis;
};

#endif