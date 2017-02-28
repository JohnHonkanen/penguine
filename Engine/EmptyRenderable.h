#pragma once
#include "Renderable.h"
class EmptyRenderable: public Renderable
{
public:
	EmptyRenderable();
	~EmptyRenderable();
	void render(Renderer* r);
};

