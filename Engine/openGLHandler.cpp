/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "openGLHandler.h"



openGLHandler::openGLHandler(Window *window)
{
	openGLHandler::window = window;
}


openGLHandler::~openGLHandler()
{
}

void openGLHandler::init()
{
	window->init();
	cout << "Window Initialized" << endl;
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	cout << "Glew Start" << endl;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	cout << "Glew Initialized" << endl;
	cout << "il Start" << endl;
	//Initialize DevIL
	ilInit();
	cout << "il Initialized" << endl;

	glm::mat4 view;
	glm::mat4 projection;
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f)); //Change Z value to move camera closer/further away from screen
	projection = glm::perspective(glm::radians(45.0f), (GLfloat)window->WIDTH / (GLfloat)window->HEIGHT, 0.1f, 100.0f);
	openGLHandler::view.setTransform(view);
	openGLHandler::projection.setTransform(projection);

	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void openGLHandler::start()
{

	//Rendering commands go here
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); //Color to clear with
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clears the screen
	
}

void openGLHandler::end()
{
	//Swap the buffers
	window->swapBuffers();
}

void openGLHandler::destroy()
{
	window->destroy();
}

