#pragma once

#include "TextureGenerator.h"

#include <GL\glew.h>
#include <map>
#include <string>

using namespace std;

enum context {
	OPENGL
};

class OGLTextureManager;
class TextureManager
{
protected:
	static TextureManager *inst;
	TextureManager();
	virtual ~TextureManager();

private:
	map<string, GLuint> textures;

public:
	static void setContext(context c);
	static TextureManager *getManager();
	virtual void saveTexture(const string fileLocation, const string textureName) = 0;
	virtual void deleteTexture(const string textureName) = 0;
	virtual void destroy() = 0;

	virtual GLuint getTexture(const string textureName) = 0;
	
};

