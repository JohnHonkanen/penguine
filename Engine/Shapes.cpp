#include "Shapes.h"

Shapes::Shapes(TextureManager * textureManager)
{
	Shapes::textureManager = textureManager;
}

Shapes::~Shapes()
{
	delete mesh;
}

Mesh * Shapes::getMesh()
{
	return Shapes::mesh;
}
