#pragma once
#include "glm\glm.hpp"

using namespace glm;

class Movement
{
public:
	Movement();
	virtual ~Movement();
	virtual mat4 init() = 0;
	virtual mat4 update(float ts) = 0;
};

