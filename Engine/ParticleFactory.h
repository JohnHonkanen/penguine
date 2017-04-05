#pragma once

#include "Particle.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Shoot.h"
#include "StaticEntity.h"
#include "Firework.h"
#include "FireworkDisplay.h"
#include "ParticleManager.h"

class ParticleFactory
{
private:
	TextureManager *textureManager;
public:
	ParticleFactory();
	void makeParticle(int choice);
	void createFireWork();

	void setTextureManager(TextureManager *textureManager);

};

