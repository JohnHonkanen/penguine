#pragma once
#include "Mesh.h"
class BasicMesh :
	public Mesh
{
public:
	BasicMesh(GLfloat *vertices, GLuint vertexCount, GLfloat *uv, GLuint *indices, GLuint indexCount, GLuint textureID);
	virtual ~BasicMesh();
	void setupMesh();
	void drawMesh();
	
};

