#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::setRenderingStrategy(RenderingStrategy * strategy)
{
	Entity::strategy = strategy;
}
