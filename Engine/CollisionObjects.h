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
private:
	vec3 position;
	ContactManifold manifold;
	vec3 halfExtents;
	bool colliding = false;
	vec3 contactNormal;
	vec3 offset;
	bool isStatic;
	CollisionObjects *collidingObjects;
public:
	CollisionObjects();
	virtual ~CollisionObjects();


};

