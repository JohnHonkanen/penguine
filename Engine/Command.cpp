#include "Command.h"

Command::Command(ParticleFactory * obj, void (ParticleFactory::* meth)())
{
	object = obj; //arguments name is "meth"
	method = meth;
}

void Command::execute()
{
	(object->*method)(); // invoke the method on the object
}
