#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#include <iostream>

#include "Renderer.h"
#include "TextureManager.h"
#include "Transform.h"
#include "Shader.h"
#include "MeshGenerator.h"
#include "Camera.h"

struct Material {
	string texture;
	string diffuse;
	string specular;
	string emission;
	float shininess;
};
class BoxRenderer : public Renderer
{
private:
	Material material;
	GLuint VAO; // 2D Mesh for the sprite
	TextureManager *textureManager;
	Transform *transform; // Origin of the renderObject
	Shader *program;
	Camera *camera2D;
public:
	BoxRenderer(Material material, TextureManager *textureManager, Transform *transform, Shader *program, Camera *camera);
	virtual ~BoxRenderer();

	void init();
	void renderObject();
};

