#pragma once
#include "TextureManager.h"

class OGLTextureManager : public TextureManager
{
private: 
	map<string, GLuint> textures;

public:
	OGLTextureManager();
	~OGLTextureManager();

	void saveTexture(const string fileLocation, const string textureName);
	void deleteTexture(const string textureName);
	void destroy();

	GLuint getTexture(const string textureName);

};

