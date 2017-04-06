#include "Entity.h"

Entity::Entity()
{
	alive = false;
	delayStarted = false;
	doesNotExpire = true;
	delayClock.setDelay(100);
	collider = nullptr;
}

Entity::Entity(Shapes *shape, float lifeTime)
{
	Entity::shape = shape;
	alive = false;
	delayStarted = false;
	delayClock.setDelay(1);
	doesNotExpire = true;
	collider = nullptr;
}

Entity::~Entity()
{
}

void Entity::update(float ts)
{
	if (!delayStarted)
	{
		delayClock.startClock();
		delayStarted = true;
	}

	if (Entity::delayClock.alarm() && !alive) {
		alive = true;
		lifeClock.startClock();
	}

	if(alive)
		Entity::lifeClock.updateClock();
	else {
		Entity::delayClock.updateClock();
	}
	Entity::shape->getMesh()->updateModelMatrix(Entity::transform.calculateModelMatrix());

	if (collider != nullptr) {
		collider->position = transform.getPosition();
		if (collider->collided) {
			cStrategy->handleCollision(this);
		}
	}
}

void Entity::setMovement(Movement * movement)
{
	Entity::movement = movement;
}

void Entity::setLifeTime(float lifeTime)
{
	if (lifeTime != 0) {
		lifeClock.setDelay(lifeTime);
	}
	doesNotExpire = false;
}

void Entity::setDelayTime(float delayTime)
{
	if (delayTime != 0) {
		delayClock.setDelay(delayTime);
	}
}

Collider * Entity::getCollider()
{
	return collider;
}

void Entity::setCollider(Collider * in_collider)
{
	collider = in_collider;
}

void Entity::setCollisionStrategy(CollisionStrategy *strategy)
{
	cStrategy = strategy;
}

Shapes * Entity::getShape()
{
	return shape;
}

bool Entity::expire()
{
	if (doesNotExpire)
		return false;
	else
	return lifeClock.alarm();
}

bool Entity::start()
{
	return alive;
}
