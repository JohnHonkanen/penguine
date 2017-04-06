/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "BasicParticle.h"


BasicParticle::BasicParticle():Particle(nullptr)
{
}

BasicParticle::BasicParticle(Particle * p, Entity * emitter, Shapes *shape, Spawner *spawn):Particle(emitter)
{
	BasicParticle::particleShape = shape;
	BasicParticle::spawn = spawn;
}

BasicParticle::~BasicParticle()
{
}

void BasicParticle::init()
{

	particle = spawn->createEntity();
}

void BasicParticle::update(float ts)
{
	if (!BasicParticle::particle->expire()) {
		particle->update(ts);
	}

}

void BasicParticle::render(Renderer * renderer)
{
	if (particle->start()) {
		renderer->renderObject(particle->getShape());
	}
	
}

void BasicParticle::destroy()
{
	delete spawn;
	delete particleMovement;
	delete this;
}
