#pragma once
#include "Transform.h"
#include "Clock.h"
#include "RenderingStrategy.h"
#include "GraphicsHandler.h"

class Entity
{
protected:
	float lifeTime;
public:
	Entity();
	virtual ~Entity();
	virtual void init() = 0;
	virtual void render(GraphicsHandler *r) = 0;
	virtual void update(float ts) = 0;
	void setRenderingStrategy(RenderingStrategy *strategy);
	Clock clock;
	Transform transform;
	RenderingStrategy *strategy;
	float alpha;
};

