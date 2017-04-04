#include "Command.h"

Command::Command(Keyboard * obj, void(Keyboard::* meth)())
{
	object = obj; //arguments name is "meth"
	method = meth;
}

void Command::execute()
{
	(object->*method)(); // invoke the method on the object
}
