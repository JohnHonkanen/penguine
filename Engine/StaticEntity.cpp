#include "StaticEntity.h"



StaticEntity::StaticEntity()
{
	strategy = nullptr;
}

StaticEntity::~StaticEntity()
{
	delete strategy;
}

void StaticEntity::init()
{

}

void StaticEntity::render()
{
	Entity::strategy->renderObject();
}

void StaticEntity::update(float ts)
{
	this->movement->update(ts);
}
