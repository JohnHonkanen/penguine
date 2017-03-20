#include "GLRenderer.h"



GLRenderer::GLRenderer(Shader *program)
{
	GLRenderer::program = program;
}


GLRenderer::~GLRenderer()
{
}

void GLRenderer::renderObject(Shapes * shape)
{
	GLuint VAO, textureID;
	GLRenderer::program->Use();

	Mesh *mesh = shape->getMesh();
	textureID = dynamic_cast<GLMesh*>(mesh)->getTextureID();
	mat4 view = camera->getView();
	mat4 projection = camera->getProjection();
	mat4 model = mesh->getModelMatrix();

	mat4 MVP = projection * view * model;

	//Get matrix's uniform location, get and set matrix
	//GLuint modelLoc = glGetUniformLocation(GLRenderer::program->Program, "model");
	GLuint MVPLoc = glGetUniformLocation(GLRenderer::program->Program, "MVP");

	//glBindTexture call will bind that texture to the currently active texture unit.
	glBindTexture(GL_TEXTURE_2D, textureID);
	//By setting them via glUniform1i we make sure each uniform sampler corresponds to the proper texture unit.
	glUniform1i(glGetUniformLocation(program->Program, "ourTexture"), 0);


	//Pass to Shader
	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(MVP));
	
	mesh->drawMesh();
}
