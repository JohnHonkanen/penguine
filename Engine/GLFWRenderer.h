#pragma once

#include <glfw3.h>
#include <GL\glew.h>

#include "Renderable.h"
#include <iostream>


using namespace std;

class GLFWRenderer :
	public Renderer 
{
private: 
	GLFWwindow *window;

	GLFWwindow *setup();
public:
	GLFWRenderer();
	virtual ~GLFWRenderer();

	void init();
	void start();
	void end();
	void destroy();

	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
};
