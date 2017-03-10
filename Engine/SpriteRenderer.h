#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <string>

#include "RenderingStrategy.h"
#include "TextureManager.h"
#include "Transform.h"
#include "Shader.h"
#include "MeshGenerator.h"

using namespace std;

class SpriteRenderer :
	public RenderingStrategy
{
private:
	string fileLocation;
	string name;
	GLuint quad; // 2D Mesh for the sprite
	TextureManager textureManager;
	Transform transform; // Origin of the renderObject
	Shader *program;

public:
	SpriteRenderer(string fileLocation, string name, TextureManager textureManager, Transform transform, Shader *program);
	virtual ~SpriteRenderer();

	void init();
	void renderObject();



};

