/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "Shapes.h"
#include "Transform.h"
#include "Clock.h"
#include "Renderer.h"
#include "Movement.h"
#include "Collider.h"
#include "CollisionStrategy.h"
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
	Collider *collider;
	CollisionStrategy *cStrategy;
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
	Collider *getCollider();
	void setCollider(Collider *collider);
	void setCollisionStrategy(CollisionStrategy *strategy);
	Shapes *getShape();
	bool expire();
	bool start();
	Transform transform;
};

