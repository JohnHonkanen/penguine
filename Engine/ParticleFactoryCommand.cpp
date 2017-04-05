#include "ParticleFactoryCommand.h"


ParticleFactoryCommand::ParticleFactoryCommand(ParticleFactory * obj, void(ParticleFactory::* meth)())
{
	object = obj; //arguments name is "meth"
	method = meth;
}

ParticleFactoryCommand::~ParticleFactoryCommand()
{
}

void ParticleFactoryCommand::execute()
{
	(object->*method)();
}
