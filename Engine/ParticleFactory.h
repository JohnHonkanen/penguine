/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once

#include "Particle.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Shoot.h"
#include "StaticEntity.h"
#include "Firework.h"
#include "FireworkDisplay.h"
#include "BasicWithCollision.h"
#include "ParticleManager.h"

class ParticleFactory
{
private:
	TextureManager *textureManager;
public:
	ParticleFactory();
	void makeParticle(int choice);
	void createFireWork();
	void createBasicParticle();

	void setTextureManager(TextureManager *textureManager);

};

