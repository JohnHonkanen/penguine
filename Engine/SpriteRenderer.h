#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#include <iostream>
#include "Renderer.h"
#include "Transform.h"
#include "Shader.h"
#include "Camera.h"


using namespace std;

class SpriteRenderer :
	public Renderer
{
private:
	Transform *transform; // Origin of the renderObject
	Shader *program;
	Camera *camera2D;
public:
	SpriteRenderer(Transform *transform, Shader *program, Camera *camera);
	virtual ~SpriteRenderer();

	void renderObject();
	void destroy();



};

