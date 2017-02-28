#include "RenderableDecorator.h"

RenderableDecorator::RenderableDecorator(Renderable * r)
{
	this->renderable = r;
}

RenderableDecorator::~RenderableDecorator()
{
}

void RenderableDecorator::render(Renderer * r)
{
	this->renderable->render(r);
}
