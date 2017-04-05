#include "TextureManager.h"
#include "OGLTextureManager.h"

TextureManager *TextureManager::inst = nullptr;

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

void TextureManager::setContext(context c)
{
	switch (c)
	{
	case OPENGL:
		TextureManager::inst = new OGLTextureManager();
		break;
	default:
		break;
	}
}

TextureManager * TextureManager::getManager()
{
	if (TextureManager::inst == nullptr)
		TextureManager::inst = new OGLTextureManager();

	return TextureManager::inst;
}

