#include "Shoot.h"

Shoot::Shoot(vec3 force)
{
	this->force = force;
}

Shoot::~Shoot()
{
}


mat4 Shoot::init()
{
	mat4 matrixTrans(1.0f);
	matrixTrans = translate(matrixTrans, force);

	return matrixTrans;
}

mat4 Shoot::update(float ts)
{
	mat4 matrixTrans(1.0f);
	return matrixTrans;
}
