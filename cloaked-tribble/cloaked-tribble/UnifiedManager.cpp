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
	distance = 0;
	return true;
}
bool UnifiedManager::Update()
{
	for(std::list<Object*>::iterator it=objectList.begin();it!=objectList.end();++it){
		Object* tmp1 = *it;
		if(tmp1->type==0)
			continue;
		Vertex* pos1 = &tmp1->position;
		/*std::cout<<"Begin check:"<<std::endl;
		std::cout<<tmp1->position.x<<","<<tmp1->position.y<<","<<tmp1->position.z<<std::endl;*/
		Vertex* vel1 = &tmp1->velocity;
		for(std::list<Object*>::iterator ti=it;ti!=objectList.end();++ti){
			if(it==ti)
				continue;
			Object* tmp2 = *it;
			
			Vertex* pos2 = &tmp2->position;
			/*std::cout<<pos2->x<<","<<pos2->y<<","<<pos2->z<<std::endl;
			std::cout<<std::pow(tmp1->position.x-tmp2->position.x,2)<<","<<std::pow(tmp1->position.y-tmp2->position.y,2)<<","<<std::pow(tmp1->position.z-tmp2->position.z,2)<<std::endl;*/
			Vertex* vel2 = &tmp2->velocity;
			distance = std::sqrt(std::pow(tmp1->position.x-tmp2->position.x,2)+
				std::pow(tmp1->position.y-tmp2->position.y,2)+
				std::pow(tmp1->position.z-tmp2->position.z,2));
			//distance = 0.1;
			//std::cout<<distance<<std::endl;
			#ifdef _DEBUG
					std::cout<<"| ";
					std::cout<<distance;
					std::cout<<" ";
					std::cout<<(tmp1->collisionRadius+tmp2->collisionRadius)<<" object1: "<<tmp1->position.x<<" Object2: "<<tmp2->position.x;
					std::cout<<" |";
			#endif
			if((distance<(tmp1->collisionRadius+tmp2->collisionRadius))){
				//if(true){
				if(tmp1->type!=100&&tmp2->type!=100){
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
							delete w;
							objectList.erase(it);
						}
					}
				}
			}
		}
	}
		for(std::list<Object*>::iterator it=objectList.begin();it!=objectList.end();++it){
			Object* tmp1 = *it;
			if(tmp1->velocity.x>0||tmp1->velocity.y>0||tmp1->velocity.z>0){
				//addObject(new Wave(&tmp1->position,&tmp1->velocity));
			}
			tmp1->position.x=(tmp1->velocity.x)+(tmp1->position.x);
			tmp1->position.y=(tmp1->velocity.y)+(tmp1->position.y);
			tmp1->position.z=(tmp1->velocity.z)+(tmp1->position.z);
			tmp1->Update();
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