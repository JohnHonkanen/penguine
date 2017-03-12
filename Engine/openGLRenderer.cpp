#include "openGLRenderer.h"



openGLRenderer::openGLRenderer(Window *window)
{
	openGLRenderer::window = window;
	Renderer::renderingStrategy = nullptr;
}


openGLRenderer::~openGLRenderer()
{
}

void openGLRenderer::init()
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
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f)); //Change Z value to move camera closer/further away from screen
	projection = glm::perspective(45.0f, (GLfloat)window->WIDTH / (GLfloat)window->HEIGHT, 0.1f, 100.0f);
	openGLRenderer::view.setTransform(view);
	openGLRenderer::projection.setTransform(projection);

	// Setup OpenGL options
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void openGLRenderer::start()
{

	//Rendering commands go here
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Color to clear with
	glClear(GL_COLOR_BUFFER_BIT); //Clears the screen
	
}

void openGLRenderer::end()
{
	//Swap the buffers
	window->swapBuffers();
}

void openGLRenderer::destroy()
{
	window->destroy();
}

void openGLRenderer::draw()
{
	if (renderingStrategy != nullptr) {
		renderingStrategy->addView(openGLRenderer::view);
		renderingStrategy->addProjection(openGLRenderer::projection);
		renderingStrategy->renderObject();
	}
}
