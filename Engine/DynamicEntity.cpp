#include "DynamicEntity.h"



DynamicEntity::DynamicEntity()
{
	this->renderable = nullptr;
}

DynamicEntity::DynamicEntity(Renderable *r, Movement* m)
{
	this->renderable = r;
	this->movement = m;
}


DynamicEntity::~DynamicEntity()
{
	delete renderable;
}

void DynamicEntity::init()
{
	this->movement->init();
}

void DynamicEntity::render(Renderer * r)
{
	renderable->render(r);
}

void DynamicEntity::update(float ts)
{
	this->movement->update(ts);
	this->physics.update(ts);
	this->transform.translate(this->physics.getAcceleration()); // Updates our Entity
}

void DynamicEntity::setRenderable(Renderable * renderable)
{
	this->renderable = renderable;
}

void DynamicEntity::setMovement(Movement * movement)
{
	this->movement = movement;
}
