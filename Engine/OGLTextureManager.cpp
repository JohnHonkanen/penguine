/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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
