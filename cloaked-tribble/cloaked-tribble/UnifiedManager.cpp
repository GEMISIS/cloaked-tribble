#include "UnifiedManager.h"
#ifdef _DEBUG
#include <iostream>
#endif
#include "Object.h"
#include "Camera.h"
#include "Wave.h"
#include <list>
#include <cmath>
#include "types.h"

UnifiedManager::UnifiedManager()
{
	Init();
}
bool UnifiedManager::Init()
{
	return true;
}
bool UnifiedManager::Update()
{
	for(std::list<Object*>::iterator it=objectList.begin();it!=objectList.end();++it){
		tmp1 = *it;
		tmp2 = *it;
		pos1 = &tmp1->position;
		pos2 = &tmp2->position;
		vel1 = &tmp1->velocity;
		vel2 = &tmp1->velocity;
		distance = sqrt(std::pow(pos1->x-pos2->x,2)+
			std::pow(pos1->y-pos2->y,2)+
			std::pow(pos1->z-pos2->z,2));
		if((distance<(tmp1->collisionRadius+tmp2->collisionRadius))){

			if(!(tmp1->type==100||tmp2->type==100)){
				//collision
				vel1->x=0;
				vel1->y=0;
				vel1->z=0;
				vel2->x=0;
				vel2->y=0;
				vel2->z=0;
			} else {

			}
		}
	}
	return true;
}
bool UnifiedManager::addObject(Object* input)
{

	return true;
}
float UnifiedManager::sqrt(float n)
{
	int k=10; //This determines the precision of sqrt.
	float x = n;
	float y = 0;
	for(int i=0;i<k;i++){
		y = 0.5*x;
		x = 0.5*((x/y)+y);
	}
	return x;
}