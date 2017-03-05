#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Physics.h"
#include "Renderable.h"
#include "Movement.h"
#include <iostream>

using namespace std;
class DynamicEntity :
	public Entity
{
public:
	DynamicEntity();
	DynamicEntity(Renderable *r, Movement* m);
	virtual ~DynamicEntity();
	void init();
	void render(Renderer *r);
	void update(float ts);
	void setRenderable(Renderable *renderable);
	void setMovement(Movement *movement);
	Transform transform;
	Physics physics;
	Renderable *renderable;
	Movement *movement;

};

