#pragma once
#include <glm\glm.hpp>
using namespace glm;
class Collider
{
public:
	Collider();
	virtual ~Collider();
	virtual bool checkCollision(Collider* other) = 0;
	virtual Collider* instantiate() = 0;

	bool collided;
	Collider* other;
	vec3 position;
};

