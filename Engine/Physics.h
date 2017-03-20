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
	void addForce(mat4 f);
	void resetForce();
	void setGravity(bool);

	vec4 getAcceleration();
private:
	bool grav = true;
	mat4 force = mat4(1.0f);
	vec4 acceleration = vec4(0.0f);
	float mass = 1;
};

