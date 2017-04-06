/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "glfwWindow.h"

glfwWindow::glfwWindow(GLuint width, GLuint height)
{
	glfwWindow::WIDTH = width;
	glfwWindow::HEIGHT = height;
}


glfwWindow::~glfwWindow()
{
}

void glfwWindow::init()
{
	cout << "Glfw inititing" << endl;
	glfwInit();
	cout << "Glfw Done" << endl;
	//Set OpenGL version to (Major, Minor). 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Explicitly tell OpenGL not to use Legacy Functionality.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Resize Window Option
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Create Window
	cout << "Creating Window" << endl;
	window = glfwCreateWindow(800, 600, "Penguine", nullptr, nullptr);
	cout << "Done Creting Window" << endl;
	glfwMakeContextCurrent(window);
	

	if (window == nullptr) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
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
