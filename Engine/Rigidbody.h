#pragma once
#include <glm\glm.hpp>
#define GRAVITY 15

using namespace glm;
class Rigidbody
{
public:
	Rigidbody();
	virtual ~Rigidbody();
	void update();
	void addForce(vec3 f);
	void addForce(float x, float y, float z);
	void resetForce();

	vec3 getAcceleration();
private:
	bool grav = true;
	vec3 force = vec3(0.0f);
	vec3 acceleration = vec3(0.0f);
	float mass = 1;
};

