#pragma once
#include <glm\glm.hpp>

#include <vector>
#include "CollisionManager.h"

using namespace std;
using namespace glm;

struct ContactManifold {
	vector<vec3> contacts;
};

class CollisionObjects
{
public:
	CollisionObjects();
	CollisionObjects(vec3 halfExtents, bool isStatic = false, vec3 offset = vec3(0));
	virtual ~CollisionObjects();

	vec3 position;
	ContactManifold manifold;
	vec3 halfExtents;
	bool colliding = false;
	vec3 contactNormal;
	vec3 offset;
	bool isStatic;
	CollisionObjects *collidingObject;
};

