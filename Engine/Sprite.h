#pragma once
#include "RenderableDecorator.h"
#include "Transform.h"
#include <string>

using namespace std;
class Sprite :
	public RenderableDecorator
{
private:
	Renderable *renderable;
	string sprite;
	Transform transform;
public:
	Sprite(Renderable *r, Transform &t);
	void render(Renderer *r);
};

