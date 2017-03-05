#pragma once
#include <vector>
#include <glm\glm.hpp>
#include "Entity.h"
#include "Spawn.h"

using namespace std;
using namespace glm;

class SingleSpawn :
	public Spawn
{
private:
	Entity *emitter;
	Entity *entity;
public:
	SingleSpawn(Entity *emitter, Entity* e);
	virtual ~SingleSpawn();
	void init();
	void update(float ts);
};

