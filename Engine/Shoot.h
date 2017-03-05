#pragma once
#include "Movement.h"
#include "DynamicEntity.h"
class Shoot :
	public Movement
{
private:
	DynamicEntity *entity;
	vec3 force;
public:
	Shoot(DynamicEntity *entity, vec3 force);
	virtual ~Shoot();
	void init();
	void update(float ts);
};

