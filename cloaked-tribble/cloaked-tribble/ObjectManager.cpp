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
				a.velocity.x=0;
				a.velocity.y=0;
				a.velocity.z=0;
				b.velocity.x=0;
				b.velocity.y=0;
				b.velocity.z=0;
				
			}
		}
	}
	//Now we have the correct velocities for each object and can move them.

	for(std::vector<Object*>::iterator it=objectList.begin();it!=objectList.end();++it){

		Object* a = *it;
		a->position.x=(a->velocity.x)+(a->position.x);
		a->position.y=(a->velocity.y)+(a->position.y);
		a->position.z=(a->velocity.z)+(a->position.z);
		a->Draw();
	}

	return true;
}
bool ObjectManager::addObject(Object* object)
{
	this->objectList.push_back(object);
	return true;
}