#pragma once
#include "AbstractSpawner.h"

using namespace glm;
class NullSpawner : public AbstractSpawner
{
public:
	NullSpawner();
	virtual ~NullSpawner();
	static NullSpawner *instance;
	static NullSpawner *getInstance();
	mat4 init();
	mat4 update(float ts);
	bool spawn();
	Entity *createEntity();
};

