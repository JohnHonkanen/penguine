#pragma once
#define _USE_MATH_DEFINES

#include <cmath> 
#include <GL\glew.h>

#include <glfw3.h>
#include "Renderer.h"
#include "Shader.h"
#include <iostream>

#include "TextureGenerator.h"
#include <map>

using namespace std;

class GLFWRenderer :
	public Renderer 
{
private: 
	Shader *program;
	GLFWwindow *window;
	GLuint VBO, VAO, EBO;
	GLuint texture1, texture2;
	map<string, GLuint> texture;
public:
	GLFWRenderer();
	virtual ~GLFWRenderer();

	void init();
	void start();
	void end();
	void destroy();
	void draw();

	void renderSprite(std::string spriteLocation, Transform transform);

};
