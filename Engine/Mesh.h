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