#pragma once
#include "glm\glm.hpp"

using namespace glm;

class Movement
{
public:
	Movement();
	virtual ~Movement();
	virtual vec3 init() = 0;
	virtual vec3 update(float ts) = 0;
};

