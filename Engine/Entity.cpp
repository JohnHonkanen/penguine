#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::setRenderingStrategy(Renderer * strategy)
{
	Entity::strategy = strategy;
}
