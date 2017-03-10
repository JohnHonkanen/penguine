#include <iostream>

#include "SpriteRenderer.h"
#include "TextureManager.h"
#include "Shader.h"
#include "Transform.h"
#include "Window.h"
#include "glfwWindow.h"
#include "openGLRenderer.h"


using namespace std;
int main(int argc, char *argv[])
{
	Window *window = new glfwWindow(800, 600);
	openGLRenderer renderer(window);
	renderer.init(); // Initialize Rendering Library
	renderer.start();  // Sets up Rendering Loop
	//renderer.draw(); // Draws Renders
	renderer.end(); //Swap Buffers
	cin.get();
	renderer.destroy();

	return 0;
}
