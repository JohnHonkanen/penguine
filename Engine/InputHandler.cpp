#include "InputHandler.h"

InputHandler::InputHandler(string n)
{
	name = n;
}

void InputHandler::setCommand(Command c)
{
	cmd = c;
}

InputHandler::~InputHandler()
{
}

void InputHandler::update(bool &running, Particle *particle)
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	SDL_Event sdlEvent;
	while (running) {
		while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT) {
				running = false;
			}

			if (sdlEvent.type == SDL_KEYDOWN) {
				switch (sdlEvent.key.keysym.sym) {

				case SDLK_ESCAPE:
					cout << "program exit cmd called" << endl;
					running = false;
					break;
				case SDLK_a:
					cout << "a pressed" << endl;
					break;
				case SDLK_SPACE:
					cout << "spawned a particle" << endl;
					particle = cmd.execute();
					break;
				default:
					cout << "default called" << endl;
					break;
				}
			}

		}
	}
	
}

void InputHandler::spawnParticles()
{
	// Spawn particles
}
