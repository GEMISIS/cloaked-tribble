#include "UnifiedManager.h"
#ifdef _DEBUG
#include <iostream>
#endif
#include "Object.h"
#include "Camera.h"
#include "Wave.h"
#include <list>
#include <iterator>
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
		pos1 = &tmp1->position;
		vel1 = &tmp1->velocity;
		for(std::list<Object*>::iterator ti=it;++ti!=objectList.end();){

			tmp2 = *it;

			pos2 = &tmp2->position;

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
					if(tmp1->type==100&&tmp2->type!=100){
						Wave* w = static_cast<Wave*>(tmp1);
						tmp2->awareness+=(w->magnitude);
						if(w->magnitude<=0){
							objectList.erase(it);
						}
					}
				}
			}
		}
		for(std::list<Object*>::iterator it=objectList.begin();it!=objectList.end();++it){
			tmp1 = *it;
			if(tmp1->velocity.x>0||tmp1->velocity.y>0||tmp1->velocity.z>0)
				addObject(new Wave(tmp1->position,tmp1->velocity));
			tmp1->position.x=(tmp1->velocity.x)+(tmp1->position.x);
			tmp1->position.y=(tmp1->velocity.y)+(tmp1->position.y);
			tmp1->position.z=(tmp1->velocity.z)+(tmp1->position.z);
			tmp1->Update();
		}
	}
	return true;
}
bool UnifiedManager::addObject(Object* input)
{
	objectList.push_front(input);
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