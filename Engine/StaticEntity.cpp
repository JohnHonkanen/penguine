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

}

void StaticEntity::update(float ts)
{
	this->movement->update(ts);
}
