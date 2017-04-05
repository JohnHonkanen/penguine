#pragma once

#include "TextureGenerator.h"

#include <GL\glew.h>
#include <map>
#include <string>

using namespace std;

class TextureManager
{
private:
	map<string, GLuint> textures;
	TextureManager();
	virtual ~TextureManager();

	static TextureManager *inst;
public:
	static TextureManager *getManager();
	void saveTexture(const string fileLocation, const string textureName);
	void deleteTexture(const string textureName);
	void destroy();

	GLuint getTexture(const string textureName);
	


	
};

