#include "Shoot.h"

Shoot::Shoot(DynamicEntity * entity, vec3 force)
{
	this->entity = entity;
	this->force = force;
}

Shoot::~Shoot()
{
}

void Shoot::init()
{
	entity->physics.addForce(force);
}

void Shoot::update(float ts)
{
}
