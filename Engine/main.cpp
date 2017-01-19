#include <SDL.h>

// Program entry point - SDL manages the actual WinMain entry point for us
int main(int argc, char *argv[])
{
	SDL_GLContext glContext; // OpenGL context handle
	SDL_Window * hWindow; // window handle

	SDL_Init(SDL_INIT_VIDEO); // initialize SDL

							  // Create 800x600 window
	hWindow = SDL_CreateWindow("SDL Test",
		100, 100, 800, 600,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	glContext = SDL_GL_CreateContext(hWindow);
	SDL_Delay(5000);

	SDL_DestroyWindow(hWindow);
	SDL_Quit();
	return 0;
}
