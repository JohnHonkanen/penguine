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
	DynamicEntity(Shapes *shape, float lifeTime);
	DynamicEntity(Movement* m);
	virtual ~DynamicEntity();
	void init();
	void render(Renderer *renderer);
	void update(float ts);
	Physics physics;

};

