#include "StaticEntity.h"



StaticEntity::StaticEntity()
{
	strategy = new RenderingStrategy();
}

StaticEntity::~StaticEntity()
{
	delete strategy;
}

void StaticEntity::init()
{

}

void StaticEntity::render(Renderer * r)
{
	r->setStrategy(Entity::strategy);
	r->draw();
}

void StaticEntity::update(float ts)
{
	this->movement->update(ts);
}
