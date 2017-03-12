#pragma once
#include "Entity.h"
#include "Transform.h"
#include "RenderingStrategy.h"
#include "Movement.h"
class StaticEntity :
	public Entity
{
public:
	StaticEntity();
	virtual ~StaticEntity();
	void init();
	void render(Renderer *r);
	void update(float ts);
	Movement *movement;
};

