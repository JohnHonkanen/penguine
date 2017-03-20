#include "BasicMesh.h"



BasicMesh::BasicMesh(GLfloat *vertices, GLuint vertexCount, GLfloat *uv, GLuint *indices, GLuint indexCount, GLuint textureID)
{
	GLMesh::vertices = vertices;
	GLMesh::uv = uv;
	GLMesh::indices = indices;
	GLMesh::vertexCount = vertexCount;
	GLMesh::indexCount = indexCount;
	GLMesh::mode = GL_TRIANGLES;

	GLMesh::textureID = textureID;
	setupMesh();
}

void BasicMesh::setupMesh()
{
	MeshData data = {
		GLMesh::vertices,
		nullptr,
		nullptr,
		GLMesh::uv,
		GLMesh::indices,
		GLMesh::vertexCount,
		GLMesh::indexCount,
		GLMesh::mode
	};

	GLMesh::VAO = MeshGenerator::createMesh(data);
}

void BasicMesh::drawMesh(){
	glBindVertexArray(GLMesh::VAO);
	glDrawElements(GLMesh::mode, GLMesh::indexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


