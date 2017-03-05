#include "StaticEntity.h"



StaticEntity::StaticEntity()
{
}

StaticEntity::StaticEntity(Renderable * r)
{
	this->renderable = r;
}


StaticEntity::~StaticEntity()
{
	delete renderable;
}

void StaticEntity::init()
{
}

void StaticEntity::render(Renderer * r)
{
	renderable->render(r);
}

void StaticEntity::update(float ts)
{
	this->movement->update(ts);
}

void StaticEntity::setRenderable(Renderable * renderable)
{
	this->renderable = renderable;
}
