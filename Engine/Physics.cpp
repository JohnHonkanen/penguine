#include "Physics.h"



Physics::Physics()
{
}


Physics::~Physics()
{
}
/*
	Updates acceleration and resets force. If gravity is on, apply that to force.
*/
void Physics::update(float ts)
{
	if (grav)
		addForce(0, -GRAVITY, 0);

	this->acceleration += this->force * ts;
	resetForce();
}
/*
	Add force
	@param vec3 vector force
*/
void Physics::addForce(vec3 f)
{
	this->force += f;
}
/*
	Add force
	@param x scalar force in x direction
	@param y scalar force in y direction
	@param z scalar force in z direction
*/
void Physics::addForce(float x, float y, float z)
{
	addForce(vec3(x, y, z));
}
/*
	Resets Force
*/
void Physics::resetForce()
{
	this->force = vec3(0.0f);
}
/*
	Gets acceleration
*/
vec3 Physics::getAcceleration()
{
	return this->acceleration;
}
