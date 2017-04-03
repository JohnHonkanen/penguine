#pragma once
#include <glm\glm.hpp>
#include "Entity.h"

using namespace glm;
class AbstractSpawnStrategy
{
public:
	virtual void configureParticle(Entity &entity) = 0;
};
