/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "Physics.h"
#include <iostream>


Physics::Physics()
{
	grav = true;
	acceleration = vec4(0.0f);
}


Physics::~Physics()
{
}
/*
	Updates acceleration and resets force. If gravity is on, apply that to force.
*/
void Physics::update(float ts)
{
	vec3 gravityForce(0.0f);
	gravityForce = vec3(0, -GRAVITY, 0);

	if (grav)
		addForce(gravityForce);

	Physics::acceleration += Physics::force * ts;
	resetForce();
}
/*
	Add force
	@param mat4 vector force
*/
void Physics::addForce(vec3 f)
{
	Physics::force += f;
}
/*
	Resets Force
*/
void Physics::resetForce()
{
	Physics::force = vec4(0.0f);
}
void Physics::setGravity(bool grav)
{
	Physics::grav = grav;
}
/*
	Gets acceleration
*/
vec3 Physics::getAcceleration()
{
	return Physics::acceleration;
}
