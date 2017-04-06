#include "OGLTextureManager.h"



OGLTextureManager::OGLTextureManager()
{
}


OGLTextureManager::~OGLTextureManager()
{
}

void OGLTextureManager::saveTexture(const string fileLocation, const string textureName)
{
	pair<string, GLuint> texturePair = pair<string, GLuint>(textureName, TextureGenerator::createTexture(fileLocation));
	textures.insert(texturePair);
}

void OGLTextureManager::deleteTexture(const string textureName)
{
	glDeleteTextures(1, &textures[textureName]);
}

void OGLTextureManager::destroy()
{
	map<string, GLuint>::iterator it = textures.begin();
	for (it; it == textures.end(); it++) {
		deleteTexture(it->first);
	}
}

GLuint OGLTextureManager::getTexture(const string textureName)
{
	return textures[textureName];
}
