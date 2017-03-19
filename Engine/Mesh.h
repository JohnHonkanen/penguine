#pragma once
#include "GL\glew.h"
#include "MeshGenerator.h"

struct Materials {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;
};

class Mesh
{
protected:
	GLuint VAO;
	GLuint textureID;

	GLfloat *vertices;
	GLfloat *normals;
	GLuint *indices;
	GLfloat *uv;
	GLuint vertexCount;
	GLuint indexCount;
	GLenum mode;

	Materials material;

public:
	Mesh();
	virtual ~Mesh();
	virtual void setupMesh() = 0;
	virtual void drawMesh() = 0;

	void getRenderInfo(GLuint &VAO, GLuint &textureID);
};
