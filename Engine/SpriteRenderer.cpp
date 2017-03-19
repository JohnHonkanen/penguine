#include "SpriteRenderer.h"



SpriteRenderer::SpriteRenderer(Transform *transform, Shader *program, Camera *camera)
{
	SpriteRenderer::transform = transform;
	SpriteRenderer::program = program;
	SpriteRenderer::camera2D = camera;

}

SpriteRenderer::~SpriteRenderer()
{
}
void SpriteRenderer::renderObject()
{
	GLuint VAO, textureID;

	shape->getMesh()->getRenderInfo(VAO, textureID);

	SpriteRenderer::program->Use();

	mat4 view = camera2D->getView();
	mat4 projection = camera2D->getProjection();
	mat4 model = transform->get();
	
	//Get matrix's uniform location, get and set matrix
	GLuint modelLoc = glGetUniformLocation(SpriteRenderer::program->Program, "model");
	GLuint viewLoc = glGetUniformLocation(SpriteRenderer::program->Program, "view");
	GLuint projectionLoc = glGetUniformLocation(SpriteRenderer::program->Program, "projection");
	GLuint alphaLoc = glGetUniformLocation(SpriteRenderer::program->Program, "ourAlpha");
	
	//glBindTexture call will bind that texture to the currently active texture unit.
	glBindTexture(GL_TEXTURE_2D, textureID);
	//By setting them via glUniform1i we make sure each uniform sampler corresponds to the proper texture unit.
	glUniform1i(glGetUniformLocation(program->Program, "ourTexture"), 0);

	
	//Pass to Shader
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniform1f(alphaLoc, Renderer::alpha);

	shape->render();

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