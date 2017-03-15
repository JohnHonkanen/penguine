#include "GraphicsHandler.h"



GraphicsHandler::GraphicsHandler()
{
}


GraphicsHandler::~GraphicsHandler()
{
}


void GraphicsHandler::setStrategy(RenderingStrategy * renderingStrategy)
{
	GraphicsHandler::renderingStrategy = renderingStrategy;
}
