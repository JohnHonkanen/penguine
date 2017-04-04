#include "SDLWindow.h"



SDLWindow::SDLWindow(GLuint width, GLuint height)
{
	SDLWindow::WIDTH = width;
	SDLWindow::HEIGHT = height;
}


SDLWindow::~SDLWindow()
{
}

void SDLWindow::init()
{
	SDL_Init(SDL_INIT_VIDEO);

	// Request an OpenGL 3.0 context.
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // double buffering on

	window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	context = SDL_GL_CreateContext(window); //Create OpenGL Context and binds the gWindow to SDL.

	SDL_GL_SetSwapInterval(1); // set swap buffers to sync with monitor's vertical refresh rate
}

void SDLWindow::swapBuffers()
{
	SDL_GL_SwapWindow(window); // swap buffers
}

void SDLWindow::destroy()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
