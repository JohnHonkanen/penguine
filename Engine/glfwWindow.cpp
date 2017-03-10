#include "glfwWindow.h"

glfwWindow::glfwWindow()
{
}


glfwWindow::~glfwWindow()
{
}

void glfwWindow::init()
{
	glfwInit();

	//Set OpenGL version to (Major, Minor). 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Explicitly tell OpenGL not to use Legacy Functionality.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Resize Window Option
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Create Window
	window = glfwCreateWindow(800, 600, "Penguine", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (window == nullptr) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
}

const GLFWwindow *glfwWindow::getWindow()
{
	return glfwWindow::window;
}

void glfwWindow::swapBuffers()
{
	//Swap the buffers
	glfwSwapBuffers(window);
}

void glfwWindow::destroy()
{
	//Terminate & Clean up resources before application exit
	glfwTerminate();
}
