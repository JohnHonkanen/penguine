#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#define GRAVITY 10

using namespace glm;
class Physics
{
public:
	Physics();
	virtual ~Physics();
	void update(float ts);
	void addForce(vec3 f);
	void resetForce();
	void setGravity(bool);

	vec3 getAcceleration();
private:
	bool grav = true;
	vec3 force = vec4(0.0f);
	vec3 acceleration = vec4(0.0f);
	float mass = 1;
};

