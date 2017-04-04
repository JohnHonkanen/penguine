#include "Entity.h"

Entity::Entity()
{
	alive = false;
	delayStarted = false;
	delayClock.setDelay(100);
}

Entity::Entity(Shapes *shape, float lifeTime)
{
	Entity::shape = shape;
	alive = false;
	delayStarted = false;
	delayClock.setDelay(1);
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
}

void Entity::setDelayTime(float delayTime)
{
	if (delayTime != 0) {
		delayClock.setDelay(delayTime);
	}
}

Shapes * Entity::getShape()
{
	return shape;
}

bool Entity::expire()
{
	return lifeClock.alarm();
}

bool Entity::start()
{
	return alive;
}
