#pragma once
#include "Shapes.h"
#include "BasicMesh.h"
class Sprite :
	public Shapes
{
private:
	void createMesh();
public:
	Sprite(std::string spriteName, TextureManager *textureManager);
	void render();
};

