#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
	delete vertices;
	delete indices;
	delete uv;
	delete normals;
}

void Mesh::updateModelMatrix(glm::mat4 modelMatrix)
{
	Mesh::modelMatrix = modelMatrix;
}

glm::mat4 Mesh::getModelMatrix()
{
	return Mesh::modelMatrix;
}
