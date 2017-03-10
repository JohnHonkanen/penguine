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

	Transform *transform = new Transform(); // Mesh Location

	SpriteRenderer sprite("container.jpg", "container", &textureManager, transform, &shaderProgram); // Set-up Sprite Renderer
	sprite.init();

	for (;;) {
		//Reset Matrix
		transform->reset();

		//Compute Transformations
		glm::vec4 vec = vec4(transform->getPosition(), 1.0f);
		transform->translate(glm::vec3(0.5f, -0.5f, 0.0f));
		transform->rotate((GLfloat)glfwGetTime() * 50.0f,glm::vec3(0.0f, 0.0f, 1.0f), false);
		transform->scale(glm::vec3(0.5f, 0.5f, 0.5f));
		glm::mat4 trans = transform->get();

		vec = trans * vec;
		cout << vec.x << vec.y << vec.z << endl;

		renderer.setStrategy(&sprite);
		renderer.start();  // Sets up Rendering Loop
		renderer.draw(); // Draws Renders
		renderer.end(); //Swap Buffers
	}

	cin.get();
	renderer.destroy();

	return 0;
}
