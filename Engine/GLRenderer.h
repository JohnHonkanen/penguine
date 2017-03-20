#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include "Renderer.h"
#include "Shader.h"
#include "GLMesh.h";
class GLRenderer :
	public Renderer
{
protected:
	Shader *program;
public:
	GLRenderer(Shader *program);
	virtual ~GLRenderer();

	void renderObject(Shapes *shape);
};

