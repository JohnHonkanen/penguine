/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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

