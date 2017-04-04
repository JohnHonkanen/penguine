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
	Particle*(ParticleFactory:: *method)();
public:
	Command(ParticleFactory *obj = 0, Particle*(ParticleFactory:: *meth)() = 0);

	Particle *execute();
};

