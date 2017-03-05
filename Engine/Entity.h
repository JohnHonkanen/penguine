#pragma once
#include "Transform.h"
#include "Renderable.h"
/*pre-definition*/
class Renderer;
/*End of pre-definition*/
class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void init() = 0;
	virtual void render(Renderer *r) = 0;
	virtual void update(float ts) = 0;
	virtual void setRenderable(Renderable *renderable)=0;
	Transform transform;
	Renderable *renderable;
};

