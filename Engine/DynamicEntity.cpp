#include "DynamicEntity.h"



DynamicEntity::DynamicEntity()
{
	this->strategy = nullptr;
}

DynamicEntity::DynamicEntity(Movement* m)
{
	this->movement = m;
}


DynamicEntity::~DynamicEntity()
{
	delete strategy;
}

void DynamicEntity::init()
{
	this->movement->init();
}

void DynamicEntity::render(Renderer * r)
{
	r->setStrategy(strategy);
	r->draw();
}

void DynamicEntity::update(float ts)
{
	this->movement->update(ts);
	this->physics.update(ts);
	this->transform.translate(this->physics.getAcceleration()); // Updates our Entity
	cout << transform.getPosition().x << " || " << transform.getPosition().y << endl;
}

void DynamicEntity::setMovement(Movement * movement)
{
	this->movement = movement;
}
