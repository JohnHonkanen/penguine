#include "StaticEntity.h"



StaticEntity::StaticEntity()
{
}

StaticEntity::~StaticEntity()
{
}

void StaticEntity::init()
{

}

void StaticEntity::render(Renderer * renderer)
{
}

Entity * StaticEntity::instantiate()
{
	return new StaticEntity();
}

void StaticEntity::update(float ts)
{
}
