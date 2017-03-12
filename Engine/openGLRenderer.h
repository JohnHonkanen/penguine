#pragma once

#include <GL\glew.h>
#include <IL\il.h>
#include <iostream>
#include "Renderer.h"
#include "Window.h"
#include "Transform.h"

using namespace std;
class openGLRenderer: public Renderer
{
private:
	Window *window;
	Transform view;
	Transform projection;
public:
	openGLRenderer(Window *window);
	virtual ~openGLRenderer();

	void init();
	void start();
	void end();
	void destroy();
	void draw();

};

