#pragma once
#include "Camera.h"
#include "Shapes.h"


using namespace glm;
class Renderer// Rendering Strategy
{
protected:
	Camera *camera;
public:
	Renderer();
	virtual ~Renderer();
	
	virtual void renderObject(Shapes *shape) = 0;

	void setCamera(Camera *camera);
};

