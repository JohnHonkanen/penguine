#pragma once

#include <iostream>
#include <string>

using namespace std;

class Keyboard;
class Command
{
private:
	Keyboard *object;
	void(Keyboard:: *method)();
public:
	Command(Keyboard *obj = 0, void(Keyboard:: *meth)() = 0);

	void execute();
};

