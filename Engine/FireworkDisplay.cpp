/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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
