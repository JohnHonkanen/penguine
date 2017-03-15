#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Movement.h"
class StaticEntity :
	public Entity
{
public:
	StaticEntity();
	virtual ~StaticEntity();
	void init();
	void render();
	void update(float ts);
	Movement *movement;
};

