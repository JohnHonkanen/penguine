#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(Shapes *shape, float lifeTime)
{
	Entity::shape = shape;
	if (lifeTime != 0) {
		lifeClock.setDelay(lifeTime);
	}
	lifeClock.startClock();
}

Entity::~Entity()
{
}

void Entity::update(float ts)
{
	Entity::lifeClock.updateClock();
	Entity::shape->getMesh()->updateModelMatrix(Entity::transform.calculateModelMatrix());
}

void Entity::setMovement(Movement * movement)
{
	Entity::movement = movement;
}

Shapes * Entity::getShape()
{
	return shape;
}

bool Entity::expire()
{
	return lifeClock.alarm();
}
