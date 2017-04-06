#pragma once
#include <glm\glm.hpp>
#include "Collider.h"

using namespace glm;
class AABBCollider :
	public Collider
{
public:
	AABBCollider(vec3 halfExtents);
	~AABBCollider();
	bool checkCollision(Collider* other);
	Collider *instantiate();
	vec3 halfExtents;
};

