#include "GLFWRenderer.h"

GLFWRenderer::GLFWRenderer()
{

}

GLFWRenderer::~GLFWRenderer()
{

}

void GLFWRenderer::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	//When user presses the escape key, we set the WindowShouldClose property to true.
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

GLFWwindow *GLFWRenderer::setup()
{
	const GLuint WIDTH = 800, HEIGHT = 600;

	//Set OpenGL version to (Major, Minor). 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Explicitly tell OpenGL not to use Legacy Functionality.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Resize Window Option
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Create Window
	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Penguine", nullptr, nullptr);

	
	glfwMakeContextCurrent(window);

	
}

void GLFWRenderer::init() {

	this->window = setup();
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;

	// Set the required callback functions
	glfwSetKeyCallback(window, this->key_callback);

	if (window == nullptr) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}
}

void GLFWRenderer::start() {
	//Checks and calls events
	glfwPollEvents();


	//Rendering commands go here
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Color to clear with
	glClear(GL_COLOR_BUFFER_BIT); //Clears the screen
	glLoadIdentity();
	glOrtho(-1000, 1000, -1000, 1000, 0.0f, 1.0f); // Reference system of our simulation

								  
	// Draw commands go here

}

void GLFWRenderer::end() {
	//Swap the buffers
	glfwSwapBuffers(window);
}

void GLFWRenderer::destroy() {

	//Terminate & Clean up resources before application exit
	glfwTerminate();
}