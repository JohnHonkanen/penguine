#include "SpriteRenderer.h"



SpriteRenderer::SpriteRenderer(string fileLocation, string name, TextureManager *textureManager, Transform *transform, Shader *program, Camera *camera)
{
	SpriteRenderer::fileLocation = fileLocation;
	SpriteRenderer::name = name;
	SpriteRenderer::textureManager = textureManager;
	SpriteRenderer::transform = transform;
	SpriteRenderer::program = program;
	SpriteRenderer::camera2D = camera;

}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::init()
{
	//Draw Quad

	 GLfloat data[] =  {
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

	SpriteRenderer::VAO = MeshGenerator::createMesh(data, sizeof(data), indices, sizeof(indices));//, VAO, VBO, EBO); //VAO
	
}

void SpriteRenderer::renderObject()
{
	SpriteRenderer::program->Use();

	mat4 view = camera2D->getView();
	mat4 projection = camera2D->getProjection();
	mat4 model = transform->get();
	
	vec3 position = transform->getPosition();
	vec3 rotation = transform->getRotation();
	position.z = -2.0f;
	model = translate(model, position);
	model = rotate(model, rotation.x, vec3(1, 0, 0));
	model = rotate(model, rotation.y, vec3(0, 1, 0));
	model = rotate(model, rotation.z, vec3(0, 0, 1));

	//Get matrix's uniform location, get and set matrix
	GLuint modelLoc = glGetUniformLocation(SpriteRenderer::program->Program, "model");
	GLuint viewLoc = glGetUniformLocation(SpriteRenderer::program->Program, "view");
	GLuint projectionLoc = glGetUniformLocation(SpriteRenderer::program->Program, "projection");
	GLuint alphaLoc = glGetUniformLocation(SpriteRenderer::program->Program, "ourAlpha");
	
	//glBindTexture call will bind that texture to the currently active texture unit.
	glBindTexture(GL_TEXTURE_2D, textureManager->getTexture(name));
	//By setting them via glUniform1i we make sure each uniform sampler corresponds to the proper texture unit.
	glUniform1i(glGetUniformLocation(program->Program, "ourTexture"), 0);

	//Draw Container
	glBindVertexArray(VAO); 
	
	//Pass to Shader
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniform1f(alphaLoc, Renderer::alpha);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void SpriteRenderer::destroy() {

	//Properly de-allocate all resources once they've outlived their purpose
	//A VAO stores the glBindBuffer calls when the target is GL_ELEMENT_ARRAY_BUFFER. This means it stores its unbind calls
	//so make sure you don't unbind the element array buffer before unbinding your VAO, otherwise it doesn't have an EBO
	//configured. 

	/*glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);*/
	delete this;
}