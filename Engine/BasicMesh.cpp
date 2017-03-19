#include "BasicMesh.h"



BasicMesh::BasicMesh(GLfloat *vertices, GLuint vertexCount, GLfloat *uv, GLuint *indices, GLuint indexCount, GLuint textureID)
{
	Mesh::vertices = vertices;
	Mesh::uv = uv;
	Mesh::indices = indices;
	Mesh::vertexCount = vertexCount;
	Mesh::indexCount = indexCount;
	Mesh::mode = GL_TRIANGLES;

	Mesh::textureID = textureID;
	setupMesh();
}


BasicMesh::~BasicMesh()
{
}

void BasicMesh::setupMesh()
{
	MeshData data = {
		Mesh::vertices,
		nullptr,
		nullptr,
		Mesh::uv,
		Mesh::indices,
		Mesh::vertexCount,
		Mesh::indexCount,
		Mesh::mode
	};

	Mesh::VAO = MeshGenerator::createMesh(data);
}

void BasicMesh::drawMesh(){

	glBindVertexArray(Mesh::VAO);
	glDrawElements(Mesh::mode, Mesh::indexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


