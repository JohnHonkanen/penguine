#pragma once
#define _USE_MATH_DEFINES

#include <cmath> 
#include <GL\glew.h>

#include <glfw3.h>
#include "Renderer.h"
#include <iostream>


using namespace std;

class GLFWRenderer :
	public Renderer 
{
private: 

	GLFWwindow *window;
public:
	GLFWRenderer();
	virtual ~GLFWRenderer();

	void init();
	void start();
	void end();
	void destroy();
	void drawVerts();

	void renderSprite(std::string spriteLocation, Transform transform);

};
