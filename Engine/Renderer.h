#pragma once

#include <GL\glew.h>

#include "Transform.h"


using namespace glm;
class Renderer// Rendering Strategy
{
protected:
	Transform view;
	Transform projection;
	float alpha;
public:
	Renderer();
	virtual ~Renderer();
	
	virtual void init() = 0;
	virtual void renderObject() = 0;

	void addView(Transform view);
	void addProjection(Transform projection);
	void setAlpha(float alpha);
	float getAlpha();
};

