#pragma once
#include <string>
#include "Transform.h"
#include "RenderingStrategy.h"


class Renderer
{
protected:
	RenderingStrategy *renderingStrategy;
public:
	Renderer();
	virtual ~Renderer();
	virtual void init() = 0;
	virtual void start() = 0;
	virtual void end() = 0;
	virtual void destroy() = 0;
	virtual void draw() = 0;
	void setStrategy(RenderingStrategy *renderingStrategy);
};

