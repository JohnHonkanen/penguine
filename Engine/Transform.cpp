#include "Transform.h"



Transform::Transform()
{
	Transform::transform = mat4(1.0f);
}


Transform::~Transform()
{
}
/*
Sets the position to a specified amount
@param vec3 position to be set
*/
void Transform::setPosition(vec3 position)
{
	
	Transform::transform[3] = vec4(position, 1.0f);
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
	Transform::transform = glm::translate(Transform::transform, translation);
}

/*
Rotates our Matrix
@param angle angle in radians to rotate
@param axis orientation to rotate
*/

void Transform::rotate(float angle, vec3 axis, bool inRadians)
{
	if (!inRadians) {
		angle *= DEG_TO_RAD;
	}

	Transform::transform = glm::rotate(Transform::transform, angle, axis);

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
	vec3 scaleVec(sx, sy, sz);
	scale(scaleVec);
}
/*
Scales our Matrix
@param sx vector3 with scalar values
*/
void Transform::scale(vec3 scale)
{
	Transform::transform = glm::scale(Transform::transform, scale);
}

void Transform::setTransform(mat4 matrix)
{
	Transform::transform = matrix;
}
/*
Moves our position to origin and store our position
*/
void Transform::moveToOrigin(vec3 offset)
{
	Transform::position = Transform::getPosition();
	Transform::translate(-position);
}
/*
	Adds back our position
*/
void Transform::returnToPosition()
{
	Transform::translate(position);
}
/*
Gets our mat4 matrix
*/
mat4 Transform::get()
{
	return Transform::transform;
}
vec3 Transform::getPosition()
{
	return Transform::transform[3];
}
/*
Resets to identity matrix
*/
void Transform::reset()
{
	Transform::transform = mat4();
}

