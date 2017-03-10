#include "openGLRenderer.h"



openGLRenderer::openGLRenderer(Window *window)
{
	openGLRenderer::window = window;
}


openGLRenderer::~openGLRenderer()
{
}

void openGLRenderer::init()
{
	window->init();

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;

	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	//Initialize DevIL
	ilInit();
}

void openGLRenderer::start()
{

	//Rendering commands go here
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Color to clear with
	glClear(GL_COLOR_BUFFER_BIT); //Clears the screen
	
}

void openGLRenderer::end()
{
	//Swap the buffers
	window->swapBuffers();
}

void openGLRenderer::destroy()
{
	window->destroy();
}

void openGLRenderer::draw()
{
	Renderer::renderingStrategy->renderObject();
}
