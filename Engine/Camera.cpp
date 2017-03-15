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
