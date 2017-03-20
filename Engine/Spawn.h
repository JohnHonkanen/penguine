#pragma once
#include <glm\glm.hpp>
#include "Entity.h"

using namespace glm;
class Spawn
{
protected:
	Entity *emitter;
public:
	Spawn();
	virtual ~Spawn();
	virtual mat4 init() = 0;
	virtual mat4 update(float ts) = 0;
	void setEmitter(Entity *entity);
};

