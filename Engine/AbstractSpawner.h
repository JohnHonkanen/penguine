#pragma once
#include <glm\glm.hpp>
#include "Entity.h"

class AbstractSpawner
{
protected:
	Entity *emitter;
	Entity *particle;
	bool spawn;
public:
	AbstractSpawner();
	~AbstractSpawner();

	virtual mat4 init() = 0;
	virtual mat4 update(float ts) = 0;
	virtual bool spawn() = 0;
	virtual Entity *createEntity() = 0;

};

