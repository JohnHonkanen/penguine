#pragma once

#include <GL\glew.h>
#include <map>

#define STORED_VERTEX       0
#define STORED_COLOR        1
#define STORED_UV           2
#define STORED_NORMAL		3
#define STORED_INDEX		4

using namespace std;

struct MeshData {

	GLfloat *vertices;
	GLfloat *normals;
	GLfloat *color;
	GLfloat *uv;
	GLuint *indices;

	GLuint vertexCount;
	GLuint indexCount;
	GLenum mode;
};

class MeshGenerator{
public:
	static GLuint createMesh(MeshData data); //, GLuint &VAO, GLuint &VBO, GLuint &EBO);
	static void updateMesh(const GLuint mesh, const unsigned int bufferType, const GLfloat *data, const GLuint size);
	static void destroy();
	static map<GLuint, GLuint *> VAOMap;
};
