#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
	destroy();
}

void Mesh::destroy()
{
}

void Mesh::updateModelMatrix(glm::mat4 modelMatrix)
{
	Mesh::modelMatrix = modelMatrix;
}

glm::mat4 Mesh::getModelMatrix()
{
	return Mesh::modelMatrix;
}
