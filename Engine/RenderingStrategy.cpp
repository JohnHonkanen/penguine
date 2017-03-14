#include "RenderingStrategy.h"



RenderingStrategy::RenderingStrategy()
{
	RenderingStrategy::alpha = 1.0f;
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

void RenderingStrategy::setAlpha(float alpha)
{
	this->alpha = alpha;
}

float RenderingStrategy::getAlpha()
{
	return RenderingStrategy::alpha;
}
