#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Physics.h"
#include "RenderingStrategy.h"
#include "Movement.h"
#include "Clock.h"
#include <iostream>

using namespace std;
class DynamicEntity :
	public Entity
{
public:
	DynamicEntity();
	DynamicEntity(float lifeTime);
	DynamicEntity(Movement* m);
	virtual ~DynamicEntity();
	void init();
	void render();
	void update(float ts);
	void setMovement(Movement *movement);
	Physics physics;
	Movement *movement;

};

