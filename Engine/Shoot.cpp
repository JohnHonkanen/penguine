#include "Shoot.h"

Shoot::Shoot(vec3 force)
{
	this->force = force;
}

Shoot::~Shoot()
{
}


vec3 Shoot::init()
{
	//Impulse
	return force;
}

vec3 Shoot::update(float ts)
{
	return vec3(0.0f);
}
