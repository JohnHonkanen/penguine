/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "ParticleFactory.h"

ParticleFactory::ParticleFactory()
{
}

void ParticleFactory::makeParticle(int choice)
{
	if (choice == 1) {
		createFireWork(); //choice 1 particle;
	}
	
	if (choice == 2) {
		//return 0; //choice 2particle;
	}
}

void ParticleFactory::createFireWork()
{

	StaticEntity *emitter =  new StaticEntity();
	//emitter.transform.translate(0, -0, -0);
	FireworkDisplay *firework = new FireworkDisplay(emitter);
	firework->init();
	ParticleManager::getManager()->addParticle(firework);
}

void ParticleFactory::createBasicParticle()
{
	StaticEntity *emitter = new StaticEntity();
	//emitter.transform.translate(0, -0, -0);
	BasicWithCollision *p = new BasicWithCollision(emitter);
	p->init();
	ParticleManager::getManager()->addParticle(p);
}

void ParticleFactory::setTextureManager(TextureManager * textureManager)
{
	ParticleFactory::textureManager = textureManager;
}
