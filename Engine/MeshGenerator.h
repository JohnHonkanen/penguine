#pragma once

#include <GL\glew.h>
#include <map>

#define VERTEX			0
#define COLOR			1
#define NORMAL			2
#define TEXCOORD		3
#define INDEX			4
#define STORED_VAO      5
#define STORED_VBO      6
#define STORED_EBO      7

using namespace std;

class MeshGenerator{
public:
	static GLuint createMesh(const GLuint numVerts, const GLfloat * vertices, const GLfloat * colors,
							 const GLfloat *normals, const GLfloat *texCoords, const GLuint indexCount, const GLuint* indices);
	static GLuint createMesh(const GLuint numVerts, const GLfloat * vertices, const GLfloat * colors,
						     const GLfloat *texCoords, const GLuint indexCount, const GLuint* indices);
	static void updateMesh(const GLuint mesh, const unsigned int bufferType, const GLfloat *data, const GLuint size);
	static void destroy();
	static map<GLuint, GLuint *> VAOMap;
};
