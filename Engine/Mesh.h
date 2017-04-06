/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include <glm\glm.hpp>
#include "MeshGenerator.h"

class Mesh
{
protected:
	glm::mat4 modelMatrix;
public:
	Mesh();
	virtual ~Mesh();
	virtual void setupMesh() = 0;
	virtual void drawMesh() = 0;
	virtual void destroy();
	void updateModelMatrix(glm::mat4 modelMatrix);
	glm::mat4 getModelMatrix();
};