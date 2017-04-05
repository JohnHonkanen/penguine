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

void ParticleFactory::setTextureManager(TextureManager * textureManager)
{
	ParticleFactory::textureManager = textureManager;
}
