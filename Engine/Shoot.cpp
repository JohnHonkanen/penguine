/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "Shoot.h"

Shoot::Shoot(vec3 force)
{
	this->force = force;
}

Shoot::~Shoot()
{
}


vec3 Shoot::init()
{
	//Impulse
	return force;
}

vec3 Shoot::update(float ts)
{
	return vec3(0.0f);
}
