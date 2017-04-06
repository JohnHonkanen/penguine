/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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

