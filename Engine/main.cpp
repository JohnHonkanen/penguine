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

	TextureManager textureManager;
	textureManager.saveTexture("container.jpg", "container");

	Shader shaderProgram("minimal.vert", "single.frag"); // Initialize Shader Programs

	Transform transform; // Mesh Location

	SpriteRenderer sprite("container.jpg", "container", &textureManager, transform, &shaderProgram); // Set-up Sprite Renderer
	sprite.init();

	renderer.setStrategy(&sprite);

	renderer.start();  // Sets up Rendering Loop
	renderer.draw(); // Draws Renders
	renderer.end(); //Swap Buffers
	cin.get();
	renderer.destroy();

	return 0;
}
