#pragma once
#include "Transform.h"
#include "RenderingStrategy.h"
#include "Renderer.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void init() = 0;
	virtual void render(Renderer *r) = 0;
	virtual void update(float ts) = 0;
	void setRenderingStrategy(RenderingStrategy *strategy);
	Transform transform;
	RenderingStrategy *strategy;
};

