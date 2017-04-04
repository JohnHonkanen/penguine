#pragma once
#include "Shapes.h"
#include "Transform.h"
#include "Clock.h"
#include "Renderer.h"
#include "Movement.h"

class Entity
{
protected:
	bool delayStarted;
	bool alive;
	bool doesNotExpire;
	Shapes *shape; 
	Clock delayClock;
	Clock lifeClock;
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
	void setLifeTime(float lifeTime);
	void setDelayTime(float delayTime);
	Shapes *getShape();
	bool expire();
	bool start();
	Transform transform;
};

