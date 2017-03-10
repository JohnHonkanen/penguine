#include "MeshGenerator.h"

map<GLuint, GLuint *> MeshGenerator::VAOMap;

GLuint MeshGenerator::createMesh(const GLuint numVerts, const GLfloat * vertices, const GLfloat * colors, 
	const GLfloat * normals, const GLfloat * texCoords, const GLuint indexCount, const GLuint* indices)
{
	GLuint VAO, VBO, EBO;
	GLuint *meshBuffers = new GLuint[5];

	//VBO = Vertex Buffer Object
	//VAO = Vertex Array Object
	//EBO = Element Buffer Object - EBO is a buffer, just like the vertex buffer object, that stores indices that OpenGL uses to
	//decide what vertices to draw. This is done by storing only the unique vertices and then 
	//specify the order at which we want to draw these vertices in. 
	//Example: Use 4 vertices to draw a square using 2 triangles instead of 6. 


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	// VBO for vertex data
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, numVerts, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)VERTEX, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(VERTEX);
	meshBuffers[VERTEX] = VBO;

	// VBO for color data
	if (colors != nullptr) {
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, 3 * numVerts*sizeof(GLfloat), colors, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(COLOR);
		meshBuffers[COLOR] = VBO;
	}

	// VBO for tex-coord data
	if (texCoords != nullptr) {
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, 2 * numVerts*sizeof(GLfloat), texCoords, GL_STATIC_DRAW);
		glVertexAttribPointer(TEXCOORD, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(TEXCOORD);
		meshBuffers[TEXCOORD] = VBO;
	}

	// VBO for normal data
	if (normals != nullptr) {
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, 3 * numVerts*sizeof(GLfloat), normals, GL_STATIC_DRAW);
		glVertexAttribPointer((GLuint)NORMAL, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(NORMAL);
		meshBuffers[NORMAL] = VBO;
	}

	// EBO for INDEX data
	if (indices != nullptr && indexCount > 0) {
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount, indices, GL_STATIC_DRAW);
		meshBuffers[INDEX] = EBO;
	}

	glBindVertexArray(0); // Unbind VAO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	meshBuffers[STORED_VAO] = VAO;
	meshBuffers[STORED_VBO] = VBO;
	meshBuffers[STORED_EBO] = EBO;

	// return the identifier needed to draw this mesh

	VAOMap.insert(pair<GLuint, GLuint *>(VAO, meshBuffers));
	return VAO;
}

GLuint MeshGenerator::createMesh(const GLuint numVerts, const GLfloat * vertices, const GLfloat * colors, const GLfloat * texCoords, const GLuint indexCount, const GLuint * indices)
{
	return MeshGenerator::createMesh(numVerts, vertices, colors, nullptr, texCoords, indexCount, indices);
}

void MeshGenerator::updateMesh(const GLuint mesh, const unsigned int bufferType, const GLfloat * data, const GLuint size)
{
	GLuint * meshBuffers = VAOMap[mesh];
	glBindVertexArray(mesh);

	// Delete the old buffer data
	glDeleteBuffers(1, &meshBuffers[bufferType]);

	// generate and set up the VBOs for the new data
	GLuint VBO;
	glGenBuffers(1, &VBO);

	// VBO for the data
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size*sizeof(GLfloat), data, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)bufferType, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(bufferType);
	meshBuffers[VERTEX] = VBO;

	glBindVertexArray(0);
}

void MeshGenerator::destroy()
{
	//Properly de-allocate all resources once they've outlived their purpose
	//A VAO stores the glBindBuffer calls when the target is GL_ELEMENT_ARRAY_BUFFER. This means it stores its unbind calls
	//so make sure you don't unbind the element array buffer before unbinding your VAO, otherwise it doesn't have an EBO
	//configured. 

	map<GLuint, GLuint*>::iterator it = VAOMap.begin();

	for (it; it == VAOMap.end(); it++) {
		glDeleteVertexArrays(1, &it->second[STORED_VAO]);
		glDeleteBuffers(1, &it->second[STORED_VBO]);
		glDeleteBuffers(1, &it->second[STORED_EBO]);
	}
}