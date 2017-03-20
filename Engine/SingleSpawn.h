#pragma once
#include <vector>
#include <glm\glm.hpp>
#include <iostream>
#include "Entity.h"
#include "Spawn.h"

using namespace std;
using namespace glm;

class SingleSpawn :
	public Spawn
{
public:
	SingleSpawn();
	virtual ~SingleSpawn();
	mat4 init();
	mat4 update(float ts);
};

