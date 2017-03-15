#include "DynamicEntity.h"



DynamicEntity::DynamicEntity()
{
	DynamicEntity::strategy = nullptr;
	DynamicEntity::lifeTime = 0.0f;
}

DynamicEntity::DynamicEntity(float lifeTime)
{
	DynamicEntity::strategy = nullptr;
	DynamicEntity::lifeTime = lifeTime;
}

DynamicEntity::DynamicEntity(Movement* m)
{
	DynamicEntity::movement = m;
}


DynamicEntity::~DynamicEntity()
{
	delete strategy;
}

void DynamicEntity::init()
{
	this->movement->init();
	if (lifeTime != 0) {
		clock.startClock();
		clock.setDelay(lifeTime);
	}
	
}

void DynamicEntity::render()
{
	Entity::strategy->renderObject();
}

void DynamicEntity::update(float ts)
{
	this->movement->update(ts);
	this->physics.update(ts);
	this->transform.translate(this->physics.getAcceleration()); // Updates our Entity

	if (lifeTime != 0) {
		clock.updateClock();
	}
}

void DynamicEntity::setMovement(Movement * movement)
{
	this->movement = movement;
}
