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

