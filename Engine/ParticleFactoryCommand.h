#pragma once
#include "Command.h"
#include "ParticleFactory.h"

class ParticleFactoryCommand :
	public Command
{
private:
	ParticleFactory *object;
	void (ParticleFactory:: *method)();
public:
	ParticleFactoryCommand(ParticleFactory *obj = 0, void (ParticleFactory:: *meth)() = 0);
	~ParticleFactoryCommand();

	void execute();
};

