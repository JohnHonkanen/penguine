#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::setStrategy(RenderingStrategy * renderingStrategy)
{
	Renderer::renderingStrategy = renderingStrategy;
}
