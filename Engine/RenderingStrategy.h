#pragma once

#include <GL\glew.h>

#include "Transform.h"


using namespace glm;
class RenderingStrategy
{
protected:
	Transform view;
	Transform projection;
	float alpha;
public:
	RenderingStrategy();
	virtual ~RenderingStrategy();

	virtual void renderObject() = 0;

	void addView(Transform view);
	void addProjection(Transform projection);
	void setAlpha(float alpha);
	float getAlpha();
};

