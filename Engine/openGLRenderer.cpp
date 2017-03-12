#include "openGLRenderer.h"



openGLRenderer::openGLRenderer(Window *window)
{
	openGLRenderer::window = window;
	Renderer::renderingStrategy = nullptr;
}


openGLRenderer::~openGLRenderer()
{
}

void openGLRenderer::init()
{
	window->init();
	cout << "Window Initialized" << endl;
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	cout << "Glew Start" << endl;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	cout << "Glew Initialized" << endl;
	cout << "il Start" << endl;
	//Initialize DevIL
	ilInit();
	cout << "il Initialized" << endl;
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
	if (renderingStrategy != nullptr) {
		renderingStrategy->renderObject();
	}
}
