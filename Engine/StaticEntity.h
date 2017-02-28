#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Renderable.h"

class StaticEntity :
	public Entity
{
public:
	StaticEntity();
	StaticEntity(Renderable *r);
	virtual ~StaticEntity();
	void render(Renderer *r);
	void update();
	Transform transform;
	Renderable *renderable;
};

