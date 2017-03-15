#pragma once
#include "Transform.h"
#include "Clock.h"
#include "Renderer.h"
#include "GraphicsHandler.h"

class Entity
{
protected:
	float lifeTime;
public:
	Entity();
	virtual ~Entity();
	virtual void init() = 0;
	virtual void render() = 0;
	virtual void update(float ts) = 0;
	void setRenderingStrategy(Renderer *strategy);
	Clock clock;
	Transform transform;
	Renderer *strategy;
	float alpha;
};

