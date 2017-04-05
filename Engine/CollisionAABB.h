#pragma once
#include "CollisionObjects.h"

class CollisionAABB : CollisionObjects
{
public:
	CollisionAABB();
	CollisionAABB(vec3 halfExtents, bool isStatic = false, vec3 offset = vec3(0));
	~CollisionAABB();
};

