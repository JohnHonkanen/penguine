#pragma once
#include <string>
#include "Transform.h"
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();
	virtual void renderSprite(std::string spriteLocation, Transform transform) = 0;
};

