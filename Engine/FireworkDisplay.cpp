#include "FireworkDisplay.h"



FireworkDisplay::FireworkDisplay(Entity *emitter): Particle(emitter)
{
}


FireworkDisplay::~FireworkDisplay()
{
}

void FireworkDisplay::init()
{
	spawnTimer.startClock();
	spawnTimer.setDelay(50);
}

void FireworkDisplay::update(float ts)
{
	spawnTimer.updateClock();
	if (spawnTimer.alarm()) {
		spawnTimer.resetClock();
		Firework f(emitter);
		f.init();
		fireworks.push_back(f);
	}
	for (int i = 0; i < fireworks.size(); i++) {
		fireworks[i].update(ts);
	}

}

void FireworkDisplay::render(Renderer * renderer)
{
	for (int i = 0; i < fireworks.size(); i++) {
		fireworks[i].render(renderer);
	}
}

void FireworkDisplay::destroy()
{
}
