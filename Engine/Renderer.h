#pragma once
#include <string>
#include "Transform.h"
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();
	virtual void renderSprite(std::string spriteLocation, Transform transform) = 0;
	virtual void init() = 0;
	virtual void start() = 0;
	virtual void end() = 0;
	virtual void destroy() = 0;
	virtual void drawVerts() = 0;
};

