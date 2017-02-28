#pragma once
#include "Renderable.h"
class RenderableDecorator :
	public Renderable
{
private:
	Renderable *renderable;
public:
	RenderableDecorator(Renderable *r);
	virtual ~RenderableDecorator();
	virtual void render(Renderer* r);
};

