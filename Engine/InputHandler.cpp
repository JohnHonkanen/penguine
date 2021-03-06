/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "InputHandler.h"

InputHandler::InputHandler(string n)
{
	name = n;
}

void InputHandler::setCommand(int key, Command * c)
{
	switch (key)
	{
	case 0:
		KEY_SPACE = c;
	case 1:
		KEY_S = c;
	case 2:
		KEY_A = c;
	default:
		break;
	}
}

InputHandler::~InputHandler()
{
}

void InputHandler::update(bool &running)
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	SDL_Event sdlEvent;
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
					KEY_A->execute();
					break;
				case SDLK_s:
					cout << "s pressed" << endl;
					KEY_S->execute();
					break;
				case SDLK_d:
					cout << "d pressed" << endl;
					break;
				case SDLK_SPACE:
					cout << "spawned a particle" << endl;
					KEY_SPACE->execute();
					break;
				default:
					cout << "default called" << endl;
					break;
				}
			}

		}
}

void InputHandler::spawnParticles()
{
	// Spawn particles
}
