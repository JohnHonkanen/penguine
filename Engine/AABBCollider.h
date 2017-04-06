#pragma once
#include <glm\glm.hpp>
#include "Collider.h"

using namespace glm;
class AABBCollider :
	public Collider
{
public:
	AABBCollider();
	~AABBCollider();
	bool checkCollision(Collider* other);
	vec3 halfExtents;
};

