#pragma once
#include "Movement.h"
#include "DynamicEntity.h"
class Shoot :
	public Movement
{
private:
	vec3 force;
public:
	Shoot(vec3 force);
	virtual ~Shoot();
	mat4 init();
	mat4 update(float ts);
};

