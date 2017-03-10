#pragma once

#include <iostream>

#include "Window.h"
#include "glfw3.h"

using namespace std;

class glfwWindow :
	public Window
{

private:
	GLFWwindow *window;
	GLuint WIDTH, HEIGHT;

public:
	glfwWindow();
	virtual ~glfwWindow();

	void init();
	const GLFWwindow *getWindow();
	void swapBuffers();
	void destroy();


};


