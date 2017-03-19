#pragma once
#include <string>
#include "Transform.h"
#include "Mesh.h"
#include "TextureManager.h"

using namespace std;

class Shapes
{
protected:
	virtual void createMesh() = 0;
	Mesh *mesh;
	string textureName;
	TextureManager *textureManager;
public:
	Shapes(TextureManager *textureManager);
	virtual ~Shapes();
	Mesh *getMesh();

};
