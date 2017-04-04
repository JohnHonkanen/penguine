#include "Firework.h"

Firework::Firework(Entity * emitter):Particle(emitter)
{
}

Firework::~Firework()
{
}

void Firework::shootRocket()
{
}

void Firework::explodeRocket()
{
}

void Firework::init()
{
	shootRocket();
}

void Firework::update(float ts)
{
	if (rocket->expire() && !exploded) {
		explodeRocket();
		exploded = true;
	}

	if (!exploded) {
		//Do rocket update
	}
	else {
		//Do explosion update
	}
}

void Firework::render(Renderer * renderer)
{
	if (!exploded) {
		//Do rocket render
	}
	else {
		//Do explosion render
	}
}

void Firework::destroy()
{
	//Destroy Fireworks
}
