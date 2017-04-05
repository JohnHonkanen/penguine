#pragma once
#include "CollisionObjects.h"

class CollisionAABB : CollisionObjects
{
public:
	CollisionAABB();
	CollisionAABB(vec3 halfExtents, bool isStatic = false, vec3 offset = vec3(0));
	~CollisionAABB();

	vec3 position;
	ContactManifold manifold;
	vec3 halfExtents;
	bool colliding = false;
	vec3 contactNormal;
	vec3 offset;
	bool isStatic;
	CollisionObjects *collidingObjects;
};

