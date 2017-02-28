#include "StaticEntity.h"



StaticEntity::StaticEntity()
{
}


StaticEntity::~StaticEntity()
{
	delete renderable;
}

void StaticEntity::render(Renderer * r)
{
	renderable->render(r);
}

void StaticEntity::update()
{
}
