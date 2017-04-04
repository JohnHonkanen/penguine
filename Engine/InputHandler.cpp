#include "InputHandler.h"

InputHandler::InputHandler(string n, Command c) : cmd(c)
{
	name = n;
}

InputHandler::~InputHandler()
{
}

void InputHandler::update()
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_Q]) {
		cout << "program exit cmd called" << endl;
		cmd.execute();
	}
}
