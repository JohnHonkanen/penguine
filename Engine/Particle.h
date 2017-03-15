#pragma once
#include "GraphicsHandler.h"
class Particle
{
public:
	Particle();
	virtual ~Particle();
	virtual void init() = 0;
	virtual void update(float ts) = 0;
	virtual void render() = 0;
	virtual void destroy() = 0;
};

