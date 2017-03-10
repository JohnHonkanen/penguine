#include "SpriteRenderer.h"



SpriteRenderer::SpriteRenderer(string fileLocation, string name, TextureManager textureManager, Transform transform, Shader *program)
{
	SpriteRenderer::fileLocation = fileLocation;
	SpriteRenderer::name = name;
	SpriteRenderer::textureManager = textureManager;
	SpriteRenderer::transform = transform;
	SpriteRenderer::program = program;
	
	//Sets quad verticies. Makes a square.
	/*quad[0] = glm::vec3(0.0f, 0.0f, 0.0f);
	quad[1] = glm::vec3(1.0f, 0.0f, 0.0f);
	quad[2] = glm::vec3(1.0f, 1.0f, 0.0f);
	quad[3] = glm::vec3(0.0f, 1.0f, 0.0f);*/

}


SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::init()
{
	//Draw Quad
	GLfloat vertices[] = {
		// Positions          
		0.5f,  0.5f, 0.0f,     // Top Right
		0.5f, -0.5f, 0.0f,     // Bottom Right
		-0.5f, -0.5f, 0.0f,    // Bottom Left
		-0.5f,  0.5f, 0.0f,    // Top Left 
	};

	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f
	};

	GLfloat textureCoords[] = {
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

	SpriteRenderer::quad = MeshGenerator::createMesh(4, vertices, colors, textureCoords, 6, indices); //VAO
}

void SpriteRenderer::renderObject()
{
	SpriteRenderer::program->Use();
	glBindTexture(GL_TEXTURE_2D, textureManager.getTexture(name));
	//By setting them via glUniform1i we make sure each uniform sampler corresponds to the proper texture unit.
	glUniform1i(glGetUniformLocation(program->Program, "texture"), 0);

	//Draw Container
	glBindVertexArray(quad);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
