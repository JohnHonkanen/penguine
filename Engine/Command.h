#pragma once

#include <iostream>
#include <string>

#include "ParticleFactory.h"

using namespace std;

class ParticleFactory;
class Command
{
private:
	ParticleFactory *object;
	void (ParticleFactory:: *method)();
public:
	Command(ParticleFactory *obj = 0, void (ParticleFactory:: *meth)() = 0);

	void execute();
};

