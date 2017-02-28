#include "Rigidbody.h"



Rigidbody::Rigidbody()
{
}


Rigidbody::~Rigidbody()
{
}
/*
	Updates acceleration and resets force. If gravity is on, apply that to force.
*/
void Rigidbody::update()
{
	if (grav)
		addForce(0, -GRAVITY, 0);

	this->acceleration += this->force;
	resetForce();
}
/*
	Add force
	@param vec3 vector force
*/
void Rigidbody::addForce(vec3 f)
{
	this->force += f;
}
/*
	Add force
	@param x scalar force in x direction
	@param y scalar force in y direction
	@param z scalar force in z direction
*/
void Rigidbody::addForce(float x, float y, float z)
{
	addForce(vec3(x, y, z));
}
/*
	Resets Force
*/
void Rigidbody::resetForce()
{
	this->force = vec3(0.0f);
}
/*
	Gets acceleration
*/
vec3 Rigidbody::getAcceleration()
{
	return this->acceleration;
}
