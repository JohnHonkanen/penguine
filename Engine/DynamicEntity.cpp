#include "DynamicEntity.h"



DynamicEntity::DynamicEntity()
{
}

DynamicEntity::DynamicEntity(Shapes *shape, float lifeTime):Entity(shape, lifeTime)
{
}

DynamicEntity::DynamicEntity(Movement* m)
{
	DynamicEntity::movement = m;
}


DynamicEntity::~DynamicEntity()
{
}

void DynamicEntity::init()
{
	DynamicEntity::physics.addForce(Entity::movement->init());
}

void DynamicEntity::render(Renderer * renderer)
{
}

void DynamicEntity::update(float ts)
{
	DynamicEntity::physics.addForce(Entity::movement->update(ts));
	DynamicEntity::physics.update(ts);
	Entity::transform.translate(DynamicEntity::physics.getAcceleration()); // Updates our Entity
	//Update Model Matrix in Mesh, delegated to Entity
	Entity::update(ts);
}
