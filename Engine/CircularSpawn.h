#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <glm\glm.hpp>
#include "Spawn.h"
#include "Entity.h"

using namespace glm;
class CircularSpawn :
	public Spawn
{
private:
	Entity *emitter;
	float radius;
	float angle;
	int numberOfPoints;
	float step;
public:
	CircularSpawn(Entity *emitter, float radius, int numberOfPoints, float startAngle = 0.0f);
	virtual ~CircularSpawn();
	void init();
	void update(float ts);
	vec2 circularPoint;
};

