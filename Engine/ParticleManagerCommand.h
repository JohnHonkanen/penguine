#pragma once
#include "Command.h"
#include "ParticleManager.h"
class ParticleManagerCommand :
	public Command
{
private:
	void (ParticleManager:: *method)();
public:
	ParticleManagerCommand(void (ParticleManager:: *method)());
	virtual ~ParticleManagerCommand();
	void execute();
};

