/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#define GRAVITY 1

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

