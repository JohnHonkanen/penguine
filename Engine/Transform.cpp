#include "Transform.h"



Transform::Transform()
{
	transform = mat4(1.0f); // Creates an identity matrix
}


Transform::~Transform()
{
}
/*
	Translates our Matrix
	@param x x-value to translate
	@param y y-value to translate
	@param z z-value to translate
*/
void Transform::translate(float x, float y, float z)
{
	vec3 translation(x, y, z);
	translate(translation);
}
/*
	Translates our Matrix
	@param translation vec3 to translate
*/
void Transform::translate(vec3 translation)
{
	glm::translate(this->transform, translation);
}
/*
	Rotates our Matrix
	@param angle angle in radians to rotate
	@param axis orientation to rotate
*/

void Transform::rotate(float angle, vec3 axis, bool inRadians)
{
	if (!inRadians)
		angle *= DEG_TO_RAD;

	glm::rotate(this->transform, angle, axis);
}
/*
	Rotates our Matrix
	@param angle angle in radians to rotate
	@param ax x-orientation to rotate
	@param ay y-orientation to rotate
	@param az z-orientation to rotate
*/

void Transform::rotate(float angle, float ax, float ay, float az, bool inRadians)
{
	if (!inRadians)
		angle *= DEG_TO_RAD;

	vec3 axis(ax, ay, az);
	rotate(angle, axis);
}
/*
	Scales our Matrix uniformly in all direction
	@param s Scalar amount
*/
void Transform::scale(float s)
{
	vec3 scaleVec(s);
	scale(scaleVec);
}
/*
	Scales our Matrix
	@param sx Scalar X amount
	@param sy Scalar Y amount
	@param sz Scalar Z amount
*/
void Transform::scale(float sx, float sy, float sz)
{
	vec3 scaleVec(sx,sy,sz);
	scale(scaleVec);
}
/*
	Scales our Matrix
	@param sx vector3 with scalar values
*/
void Transform::scale(vec3 scale)
{
	glm::scale(this->transform, scale);
}
/*
	Gets our mat4 matrix
*/
mat4 Transform::get()
{
	return this->transform;
}
vec3 Transform::getPosition()
{
	return vec3(this->transform[3]);
}
/*
	Resets to identity matrix
*/
void Transform::reset()
{
	this->transform = mat4(1);
}

