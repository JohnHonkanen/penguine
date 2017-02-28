#include "DynamicEntity.h"



DynamicEntity::DynamicEntity()
{
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
