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

class SpriteRenderer :
	public Renderer
{
public:
	SpriteRenderer(Camera *camera);
	virtual ~SpriteRenderer();

	void renderObject();
	void destroy();



};

