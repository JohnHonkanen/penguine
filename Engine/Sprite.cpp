#include "Sprite.h"

Sprite::Sprite(Renderable * r, Transform *t): RenderableDecorator(r)
{
	this->transform = t;
}

void Sprite::render(Renderer * r)
{
	//r->renderSprite(sprite, *transform);
}
