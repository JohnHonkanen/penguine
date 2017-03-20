#pragma once
#include "GL\glew.h"
#include "Mesh.h"

struct Materials {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;
};

class GLMesh :
	public Mesh
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
	GLMesh();
	virtual void setupMesh() = 0;
	virtual void drawMesh() = 0;
	virtual void destroy();
	GLuint getTextureID();
};

