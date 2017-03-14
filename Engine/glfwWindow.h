#pragma once

#include <iostream>
#include <glfw3.h>

#include "Window.h"


using namespace std;

class glfwWindow :
	public Window
{

private:
	GLFWwindow *window;

public:
	glfwWindow(GLuint WIDTH, GLuint HEIGHT);
	virtual ~glfwWindow();

	void init();
	void swapBuffers();
	void destroy();


};


