#pragma once
#include <glm\glm.hpp>

using namespace glm;
class AbstractSpawnStrategy
{
public:
	virtual vec3 spawnLocation(vec3 location) = 0;
};
