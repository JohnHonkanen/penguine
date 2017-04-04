#pragma once

#include <SDL.h>
#include "Window.h"

class SDLWindow :
	public Window
{
private:
	SDL_Window *window;
	SDL_GLContext context;
public:
	SDLWindow(GLuint WIDTH, GLuint HEIGHT);
	~SDLWindow();

	void init();
	void swapBuffers();
	void destroy();

};

