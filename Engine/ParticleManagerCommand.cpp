#include "ParticleManagerCommand.h"

ParticleManagerCommand::ParticleManagerCommand(void(ParticleManager::* meth)())
{
	method = meth;
}

ParticleManagerCommand::~ParticleManagerCommand()
{
}

void ParticleManagerCommand::execute()
{
	(ParticleManager::getManager()->*method)();
}
