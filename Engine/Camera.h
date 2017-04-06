/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include <glm\glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;
class Camera
{
protected:
	mat4 view;
	mat4 projection;
public:
	Camera();
	virtual ~Camera();

	void setPerspectiveProjection(float FOV, float aspectRatio, float zNear, float zFar);
	void setOrthoProjection(vec3 min, vec3 max); //Ortho Camera in World Coordinates
	void setView(vec3 position);
	mat4 getProjection();
	mat4 getView();
};

