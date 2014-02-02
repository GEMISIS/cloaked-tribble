#include "ObjectManager.h"
#include <cmath>
#include <vector>
#include "types.h"
#include "Object.h"

ObjectManager::ObjectManager()
{
}

bool ObjectManager::Init(){
	distance=0;
	return true;
}
bool ObjectManager::Update()
{
	//iterate through the objectList vector and check each collison

	for(std::vector<Object*>::iterator it=objectList.begin();it!=objectList.end();++it){
		//for each object after this object
		for(std::vector<Object*>::iterator ti=(it + 1);ti!=objectList.end();++ti){
			Object a = **it;
			Object b = **ti;
			distance = std::sqrt(std::pow(a.position.x+b.position.x,2)+
				std::pow(a.position.y+b.position.y,2)+
				std::pow(a.position.z+b.position.z,2));
			if(distance<=(a.collisionRadius+b.collisionRadius)){
				//we have a collision, set both objects' velocity to 0
				//a.velocity.angle=0;
				//b.velocity.angle=0;
				
			}
		}
	}
	//Now we have the correct velocities for each object and can move them.

	for(std::vector<Object*>::iterator it=objectList.begin();it!=objectList.end();++it){

		Object* a = *it;
		/**
		//velocity must be broken into x,y,z components
		a->position.x+=(a->velocity.axis.x * std::sin(a->velocity.angle/2));
		a->position.y+=(a->velocity.axis.y * std::sin(a->velocity.angle/2));
		a->position.z+=(a->velocity.axis.z * std::sin(a->velocity.angle/2));
		//update the object's quat
		a->rotation.axis.x=(a->position.x/std::sin(a->rotation.angle/2));
		a->rotation.axis.y=(a->position.y/std::sin(a->rotation.angle/2));
		a->rotation.axis.z=(a->position.z/std::sin(a->rotation.angle/2));
		*/
		a->Draw();
	}

	return true;
}
<<<<<<< HEAD
bool ObjectManager::addObject(Object object)
{
	objectList.push_back(object);
	return true;
=======

void ObjectManager::addObject(Object* object)
{
	this->objectList.push_back(object);
>>>>>>> Fixes and Walls
}