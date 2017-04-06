/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::setPerspectiveProjection(float FOV, float aspectRatio, float zNear, float zFar)
{
	Camera::projection = glm::perspective(FOV, aspectRatio, zNear, zFar);
}

void Camera::setOrthoProjection(vec3 min, vec3 max)
{
	Camera::projection = glm::ortho(min.x, max.x, min.y, max.y, min.z, max.z);
}

void Camera::setView(vec3 position)
{
	view = translate(view, position);
}

mat4 Camera::getProjection()
{
	return Camera::projection;
}

mat4 Camera::getView()
{
	return Camera::view;
}
