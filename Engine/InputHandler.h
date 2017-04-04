#pragma once

#include <SDL.h>
#include "Command.h"

class InputHandler : Command
{
private:
	string name;

	// cmd is a "black box", it is a method invocation promoted to "full object status"
	Command cmd;

	const Uint8 *keys;
public:
	InputHandler(string name, Command c);
	virtual ~InputHandler();

	void update();


};

