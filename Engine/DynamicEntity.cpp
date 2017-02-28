#include "DynamicEntity.h"



DynamicEntity::DynamicEntity()
{
	this->renderable = nullptr;
}

DynamicEntity::DynamicEntity(Renderable *r)
{
	this->renderable = r;
}


DynamicEntity::~DynamicEntity()
{
	delete renderable;
}

void DynamicEntity::render(Renderer * r)
{
	renderable->render(r);
}

void DynamicEntity::update()
{
	this->rigidbody.update();
	this->transform.translate(this->rigidbody.getAcceleration()); // Updates our Entity
}
