#pragma once
#include "Spawn.h"
#include "Entity.h"
#include <cmath>
#include <stdlib.h>
#include <glm\glm.hpp>

using namespace glm;
using namespace std;

class ConeSpawn :
	public Spawn
{
private:
	Entity *emitter;
	float baseSize;
public:
	ConeSpawn(Entity *emitter, vec3 at, float baseSize);
	virtual ~ConeSpawn();;
	void init();
	void update(float ts);
	vec3 at;
};

