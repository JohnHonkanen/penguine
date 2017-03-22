#pragma once
#include "Shapes.h"
#include "Transform.h"
#include "Clock.h"
#include "Renderer.h"
#include "Movement.h"

class Entity
{
protected:
	Shapes *shape; 
	
	Movement *movement;
	float alpha;
public:
	Entity();
	Entity(Shapes *shape, float lifeTime = 0);
	virtual ~Entity();
	virtual void init() = 0;
	virtual void render(Renderer *renderer) = 0;
	virtual void update(float ts);
	virtual Entity* instantiate() = 0;
	void setMovement(Movement *movement);
	Shapes *getShape();
	bool expire();
	Clock lifeClock;
	Transform transform;
};

