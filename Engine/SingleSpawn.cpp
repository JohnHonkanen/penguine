#include "SingleSpawn.h"

SingleSpawn::SingleSpawn(Entity *emitter, Entity* e)
{
	this->emitter = emitter;
	this->entity = e;
}

SingleSpawn::~SingleSpawn()
{
}

void SingleSpawn::init()
{
	vec3 ePos = emitter->transform.getPosition();
	this->entity->transform.setPosition(ePos);
	//vec3 pos = SingleSpawn::entity->transform.getPosition();
}

void SingleSpawn::update(float ts)
{
	/*
		Do nothing
	*/
}