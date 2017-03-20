#include "Spawn.h"



Spawn::Spawn()
{
}


Spawn::~Spawn()
{
}

void Spawn::setEmitter(Entity * entity)
{
	Spawn::emitter = entity;
}