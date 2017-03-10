#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <glfw3.h>

class Shader
{
public:
	GLuint Program;
	Shader(const char *vertexPath, const char *fragmentPath); //Initiate Shaders & Checks for errors
	void Use(); // Uses the current shader
};

#endif