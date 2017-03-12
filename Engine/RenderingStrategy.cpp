#include "RenderingStrategy.h"



RenderingStrategy::RenderingStrategy()
{
}


RenderingStrategy::~RenderingStrategy()
{
}

void RenderingStrategy::addView(Transform view)
{
	RenderingStrategy::view = view;
}

void RenderingStrategy::addProjection(Transform projection)
{
	RenderingStrategy::projection = projection;
}
