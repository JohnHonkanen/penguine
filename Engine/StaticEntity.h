#pragma once
#include "Entity.h"
#include "Transform.h"
#include "AbstractRenderable.h"

class StaticEntity :
	public Entity
{
public:
	StaticEntity();
	virtual ~StaticEntity();
	void render(Renderer *r);
	void update();
	Transform transform;
	AbstractRenderable *renderable;
};

