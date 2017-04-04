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
	vec3 init();
	vec3 update(float ts);
};

