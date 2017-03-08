#pragma once
#include <string>
#include "Transform.h"
#include <IL\il.h>
#include <IL\ilu.h>
#include <IL\ilut.h>

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
	virtual void draw() = 0;
	virtual void loadTextures() = 0; 
};

