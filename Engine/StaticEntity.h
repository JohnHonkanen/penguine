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
	void render(Renderer *renderer);
	void update(float ts);
};

