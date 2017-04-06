/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Physics.h"
#include "Renderer.h"
#include "Clock.h"
#include <iostream>

using namespace std;
class DynamicEntity :
	public Entity
{
public:
	DynamicEntity();
	DynamicEntity(Shapes *shape);
	DynamicEntity(Movement* m);
	virtual ~DynamicEntity();
	void init();
	void render(Renderer *renderer);
	void update(float ts);
	Entity* instantiate();
	Physics physics;

};

