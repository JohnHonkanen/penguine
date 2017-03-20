#pragma once
#include "GLMesh.h"
class BasicMesh :
	public GLMesh
{
public:
	BasicMesh(GLfloat *vertices, GLuint vertexCount, GLfloat *uv, GLuint *indices, GLuint indexCount, GLuint textureID);
	void setupMesh();
	void drawMesh();
};

