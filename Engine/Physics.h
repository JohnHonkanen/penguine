#pragma once
#include <glm\glm.hpp>
#define GRAVITY 15

using namespace glm;
class Physics
{
public:
	Physics();
	virtual ~Physics();
	void update(float ts);
	void addForce(vec3 f);
	void addForce(float x, float y, float z);
	void resetForce();
	void setGravity(bool);

	vec3 getAcceleration();
private:
	bool grav = false;
	vec3 force = vec3(0.0f);
	vec3 acceleration = vec3(0.0f);
	float mass = 1;
};

