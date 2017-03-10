#include <iostream>

#include "TextureManager.h"
#include "Shader.h"
#include "Window.h"
#include "glfwWindow.h"
#include "openGLRenderer.h"
#include "BallGenerator.h"


using namespace std;
using namespace glm;

int main(int argc, char *argv[])
{
	
	Window *window = new glfwWindow(800, 600);
	openGLRenderer renderer(window);
	renderer.init(); // Initialize Rendering Library

	TextureManager textureManager;
	textureManager.saveTexture("container.jpg", "container");

	Shader shaderProgram("minimal.vert", "single.frag"); // Initialize Shader Programs

	BallGenerator ballGen(vec3(0.0f), vec3(1.0f, 0.0f, 0.0f), &textureManager, &shaderProgram);
	ballGen.init();

	for (;;) {
		
		ballGen.update(1); //updates balls

		renderer.start();  // Sets up Rendering Loop
		ballGen.render(&renderer); // Renders Balls
		
						 
		renderer.end(); //Swap Buffers
	}

	cin.get();
	renderer.destroy();

	return 0;
}
