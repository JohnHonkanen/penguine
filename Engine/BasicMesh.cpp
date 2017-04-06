/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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


