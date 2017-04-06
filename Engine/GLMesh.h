/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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

