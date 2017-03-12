#pragma once

#include <GL\glew.h>

#include "Transform.h"


using namespace glm;
class RenderingStrategy
{
protected:
	Transform view;
	Transform projection;
public:
	RenderingStrategy();
	virtual ~RenderingStrategy();

	virtual void renderObject() = 0;

	void addView(Transform view);
	void addProjection(Transform projection);
};

