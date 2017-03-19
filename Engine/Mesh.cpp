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

void Mesh::getRenderInfo(GLuint & VAO, GLuint & textureID)
{
	VAO = Mesh::VAO;
	textureID = Mesh::textureID;
}
