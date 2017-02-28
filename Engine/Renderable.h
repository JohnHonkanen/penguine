#pragma once
#include "Renderer.h"
class Renderable
{
public:
	Renderable();
	virtual ~Renderable();
	virtual void render(Renderer* r) = 0;
};

