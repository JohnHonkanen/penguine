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

