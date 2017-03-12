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
	vec3 pos = entity->transform.getPosition();
	
	entity->transform.translate(pos);
	entity->transform.rotate(-0.01f, vec3(0, 0, 1));
	entity->transform.translate(-pos);

}
