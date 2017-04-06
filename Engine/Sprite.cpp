/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "Sprite.h"



Sprite::Sprite(std::string spriteName, TextureManager *textureManager): Shapes(textureManager)
{
	Shapes::textureName = spriteName;
	createMesh();
}

Shapes * Sprite::instantiate()
{
	Shapes *shape = new Sprite(Shapes::textureName, Shapes::textureManager);
	return shape;
}

void Sprite::createMesh()
{
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

	GLfloat vertices[] = {
		0.5f,  0.5f, 0.0f,
		0.5f,  -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	GLfloat uv[] = {
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};

	Shapes::mesh = new BasicMesh(vertices, 4, uv, indices, 6, textureManager->getTexture(Shapes::textureName));
}
