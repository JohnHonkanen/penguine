#include "Command.h"

Command::Command(ParticleFactory * obj, Particle*(ParticleFactory::* meth)())
{
	object = obj; //arguments name is "meth"
	method = meth;
}

Particle *Command::execute()
{
	return (object->*method)(); // invoke the method on the object
}
