#pragma once

#include "Particle.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Shoot.h"
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

