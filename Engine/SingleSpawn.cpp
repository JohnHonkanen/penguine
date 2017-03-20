#include "SingleSpawn.h"

SingleSpawn::SingleSpawn()
{
}

SingleSpawn::~SingleSpawn()
{
}

mat4 SingleSpawn::init()
{
	mat4 matrix(1.0f);
	vec3 ePos = Spawn::emitter->transform.getPosition();
	matrix = translate(matrix, ePos);
	return matrix;
}

mat4 SingleSpawn::update(float ts)
{
	/*
		Do nothing
	*/
	mat4 matrix(1.0f);
	return matrix;
}