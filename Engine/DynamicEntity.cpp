/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "DynamicEntity.h"



DynamicEntity::DynamicEntity()
{
}

DynamicEntity::DynamicEntity(Shapes *shape):Entity(shape)
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
	if (alive) {
		DynamicEntity::physics.addForce(Entity::movement->update(ts));
		DynamicEntity::physics.update(ts);
		Entity::transform.translate(DynamicEntity::physics.getAcceleration()); // Updates our Entity
	}
	//Update Model Matrix in Mesh, delegated to Entity
	Entity::update(ts);
}

Entity * DynamicEntity::instantiate()
{
	DynamicEntity *entity = new DynamicEntity(shape->instantiate());
	entity->setMovement(movement);
	return entity;
}
