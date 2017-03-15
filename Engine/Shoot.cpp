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
	entity->transform.rotate(radians(45.0f)*ts, vec3(0,0,1));
}
