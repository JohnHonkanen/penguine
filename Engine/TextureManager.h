/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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

