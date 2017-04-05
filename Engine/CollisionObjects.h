#pragma once
#include <glm\glm.hpp>

#include <vector>
#include "CollisionManager.h"

using namespace std;
using namespace glm;

class CollisionObjects
{
public:
	CollisionObjects();
	virtual ~CollisionObjects();

	bool colliding = false;
	vec3 contactNormal;
	vec3 offset;
	bool isStatic;
	CollisionObjects *collidingObjects;


};

