#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Renderable.h"
#include "Movement.h"
class StaticEntity :
	public Entity
{
public:
	StaticEntity();
	StaticEntity(Renderable *r);
	virtual ~StaticEntity();
	void init();
	void render(Renderer *r);
	void update(float ts);
	void setRenderable(Renderable *renderable);
	Transform transform;
	Renderable *renderable;
	Movement *movement;
};

