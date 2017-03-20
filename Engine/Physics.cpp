#include "Physics.h"
#include <iostream>


Physics::Physics()
{
	grav = true;
}


Physics::~Physics()
{
}
/*
	Updates acceleration and resets force. If gravity is on, apply that to force.
*/
void Physics::update(float ts)
{
	mat4 gravityForce(1.0f);
	gravityForce =  translate(gravityForce, vec3(0, -GRAVITY, 0));

	if (grav)
		addForce(gravityForce);

	Physics::acceleration += Physics::force[3] * ts;
	resetForce();
}
/*
	Add force
	@param mat4 vector force
*/
void Physics::addForce(mat4 f)
{
	Physics::force += f;
}
/*
	Resets Force
*/
void Physics::resetForce()
{
	Physics::force = mat4(0.0f);
}
void Physics::setGravity(bool grav)
{
	Physics::grav = grav;
}
/*
	Gets acceleration
*/
vec4 Physics::getAcceleration()
{
	return Physics::acceleration;
}
