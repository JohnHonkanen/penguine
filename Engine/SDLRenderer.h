#pragma once
#include <SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <glfw3.h>
#include "Renderer.h"
#include <iostream>

using namespace std;
class SDLRenderer :
	public Renderer
{
private:
	SDL_GLContext glContext;
	SDL_Window *window;

	SDL_Window *setup(SDL_GLContext &context);
public:
	SDLRenderer();
	virtual ~SDLRenderer();
	void init();
	void start();
	void end();
	void destroy();

	void renderSprite(std::string spriteLocation, Transform transform);
};

