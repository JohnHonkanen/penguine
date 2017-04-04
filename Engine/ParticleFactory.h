#pragma once

#include "Sprite.h"
#include "TextureManager.h"
#include "SingleParticle.h"
#include "Shoot.h"
#include "SingleSpawn.h"
#include "StaticEntity.h"

class ParticleFactory
{
private:
	TextureManager *textureManager;
public:
	ParticleFactory();
	Particle *makeParticle(int choice);
	Particle *createSingle();

	void setTextureManager(TextureManager *textureManager);

};

