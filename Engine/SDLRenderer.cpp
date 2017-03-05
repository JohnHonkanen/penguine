#include "SDLRenderer.h"

SDL_Window *SDLRenderer::setup(SDL_GLContext & context)
{
	SDL_Window * window;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialize video
	{
		//Exception Here
	}

	// Request an OpenGL 3.0 context.
	// Not able to use SDL to choose profile (yet), should default to core profile on 3.2 or later
	// If you request a context not supported by your drivers, no OpenGL context will be created

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // double buffering on
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4); // Turn on x4 multisampling anti-aliasing (MSAA)

													   // Create 800x600 window
	window = SDL_CreateWindow("SDL/GLM/OpenGL Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if (!window) // Check window was created OK
	{
		//Exception Here
	}

	context = SDL_GL_CreateContext(window); // Create opengl context and attach to window
	SDL_GL_SetSwapInterval(1); // set swap buffers to sync with monitor's vertical refresh rate
	return window;
}

SDLRenderer::SDLRenderer()
{
}


SDLRenderer::~SDLRenderer()
{
}

void SDLRenderer::init()
{
	this->window = setup(this->glContext);
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) { // glewInit failed, something is seriously wrong
		std::cout << "glewInit failed, aborting." << std::endl;
		exit(1);
	}
}

void SDLRenderer::start()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(-1000, 1000, -1000, 1000, 0.0f, 1.0f); // Reference system of our simulation
	glColor3f(0.5, 1.0, 1.0);
}

void SDLRenderer::end()
{
	SDL_GL_SwapWindow(window);
}

void SDLRenderer::destroy()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SDLRenderer::renderSprite(std::string spriteLocation, Transform transform)
{
	//Temp code for rendering sprite Rendering Circles instead
	const float STEP = 2 * M_PI / 30;
	vec3 pos = transform.getPosition();
	cout << transform.getPosition().x << " || " << transform.getPosition().y << std::endl;
	glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
	for (float angle = 0; angle < 2 * M_PI; angle += STEP) {
		double x = 10 * cos(angle);
		double y = 10 * sin(angle);
		glVertex3d(x + pos.x, y + pos.y, 0.0);
	}
	glEnd();
}
