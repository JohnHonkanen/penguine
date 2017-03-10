#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Physics.h"
#include "RenderingStrategy.h"
#include "Movement.h"
#include <iostream>

using namespace std;
class DynamicEntity :
	public Entity
{
public:
	DynamicEntity();
	DynamicEntity(Movement* m);
	virtual ~DynamicEntity();
	void init();
	void render(Renderer *r);
	void update(float ts);
	void setMovement(Movement *movement);
	Transform transform;
	Physics physics;
	Movement *movement;

};

