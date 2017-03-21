#include "SpawnerDecorator.h"



SpawnerDecorator::SpawnerDecorator()
{
}


SpawnerDecorator::~SpawnerDecorator()
{
	delete spawner;
}

mat4 SpawnerDecorator::init()
{
	return spawner->init();
}

mat4 SpawnerDecorator::update(float ts)
{
	return spawner->update(ts);
}

bool SpawnerDecorator::spawn()
{
	return spawner->spawn();
}

Entity * SpawnerDecorator::createEntity()
{
	return spawner->createEntity();
}
