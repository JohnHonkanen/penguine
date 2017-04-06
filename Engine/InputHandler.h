#pragma once

#include <SDL.h>
#include <map>
#include "Command.h"

class InputHandler
{
private:
	string name;

	// cmd is a "black box", it is a method invocation promoted to "full object status"
	//map<string, Command*> commandList;
	Command *KEY_SPACE;
	Command *KEY_S;
	Command *KEY_A;
	const Uint8 *keys;
public:
	InputHandler(string name);
	void setCommand(int key, Command *c);
	virtual ~InputHandler();

	void update(bool &running);

	void spawnParticles();



};

