#pragma once
#include "Transform.h"
#include "Clock.h"
#include "RenderingStrategy.h"
#include "Renderer.h"

class Entity
{
protected:
	float lifeTime;
public:
	Entity();
	virtual ~Entity();
	virtual void init() = 0;
	virtual void render(Renderer *r) = 0;
	virtual void update(float ts) = 0;
	void setRenderingStrategy(RenderingStrategy *strategy);
	Clock clock;
	Transform transform;
	RenderingStrategy *strategy;
	float alpha;
};

