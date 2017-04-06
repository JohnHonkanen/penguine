/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "BasicWithCollision.h"
#include "LocationSpawnStrategy.h"
#include "EntitySpawnStrategy.h"
#include "DelayedSpawn.h"
#include "LifeTimeSpawn.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Shoot.h"
#include "OutputConsoleCollision.h"
#include "AABBCollider.h"
#include "ColliderSpawn.h"

BasicWithCollision::BasicWithCollision(Entity *emitter):Particle(emitter)
{
}


BasicWithCollision::~BasicWithCollision()
{
}

void BasicWithCollision::createParticle()
{
	Sprite *sprite = new Sprite("particle", TextureManager::getManager());

	AbstractSpawnStrategy *locStrat = new LocationSpawnStrategy(vec3(0, -30, -50));
	EntitySpawnStrategy *spawnStrat = new EntitySpawnStrategy(locStrat, emitter);
	DelayedSpawn *delay = new DelayedSpawn(spawnStrat, 100);
	LifeTimeSpawn *life = new LifeTimeSpawn(delay, 1000, 10000);
	ColliderSpawn *coll = new ColliderSpawn(life, new AABBCollider(vec3(1)), new OutputConsoleCollision());

	Spawner spawn;
	spawn.setSpawnStrategy(coll);
	spawn.setSpawnEntity(new DynamicEntity(sprite));
	spawn.setEmitterEntity(emitter);

	//float angle = rand() % 50 - 25;
	float up = rand() % 50 + 40;

	spawn.setMovementStrategy(new Shoot(vec3(0, up, 0)));
	particle = BasicParticle(nullptr, emitter, sprite, &spawn);

	particle.init();
}

void BasicWithCollision::init()
{
	createParticle();
}

void BasicWithCollision::update(float ts)
{
	if (!particle.particle->expire()) {
		particle.update(ts);
	}
}

void BasicWithCollision::render(Renderer * renderer)
{
	if (!particle.particle->expire()) {
		particle.render(renderer);
	}
}

void BasicWithCollision::destroy()
{
}
