#include "Firework.h"
#include "LocationSpawnStrategy.h"
#include "EntitySpawnStrategy.h"
#include "DelayedSpawn.h"
#include "LifeTimeSpawn.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Shoot.h"

Firework::Firework(Entity * emitter):Particle(emitter)
{
}

Firework::~Firework()
{
}

void Firework::shootRocket()
{
	Sprite *sprite = new Sprite("particle", TextureManager::getManager());

	float xPos = rand() % 60 - 30;
	float zPos = rand() %  30 + 40;
	AbstractSpawnStrategy *locStrat = new LocationSpawnStrategy(vec3(xPos, -30, -zPos));
	EntitySpawnStrategy *spawnStrat = new EntitySpawnStrategy(locStrat, emitter);
	DelayedSpawn *delay = new DelayedSpawn(spawnStrat, 100);
	LifeTimeSpawn *life = new LifeTimeSpawn(delay, 1000, 2000);

	Spawner spawn;
	spawn.setSpawnStrategy(life);
	spawn.setSpawnEntity(new DynamicEntity(sprite));
	spawn.setEmitterEntity(emitter);

	float angle = rand() % 50 - 25;
	float up = rand() % 50 + 40;

	spawn.setMovementStrategy(new Shoot(vec3(angle, up, 0)));
	rocket = BasicParticle(nullptr, emitter, sprite, &spawn);

	rocket.init();
}

void Firework::explodeRocket()
{
	int numParticles = 10;
	
	float PI2 = 6.28;
	float steps = 6.28 / numParticles;
	for (float angle = 0; angle < PI2; angle+=steps) {
		Sprite sprite = Sprite("particle", TextureManager::getManager());

		AbstractSpawnStrategy *locStrat = new LocationSpawnStrategy(vec3(0, 0, -10));
		EntitySpawnStrategy *spawnStrat = new EntitySpawnStrategy(locStrat, rocket.particle);
		DelayedSpawn *delay = new DelayedSpawn(spawnStrat, 1);
		LifeTimeSpawn *life = new LifeTimeSpawn(delay, 1000);

		Spawner spawn;
		spawn.setSpawnStrategy(life);
		spawn.setSpawnEntity(new DynamicEntity(&sprite));
		spawn.setEmitterEntity(emitter);

		//Calc Circular Shoot
		vec2 dir = vec2(cos(angle), sin(angle));
		dir = normalize(dir);
		vec3 force = vec3(dir, 0.0f) * 10.0f;

		spawn.setMovementStrategy(new Shoot(force));
		BasicParticle p(nullptr, emitter, &sprite, &spawn);
		p.init();
		explosion.push_back(p);
	}
}

void Firework::init()
{
	shootRocket();
}

void Firework::update(float ts)
{
	if (rocket.particle->expire() && !exploded) {
		explodeRocket();
		exploded = true;
	}

	if (!exploded) {
		//Do rocket update
		rocket.update(ts);
	}
	else {
		//Do explosion update
		for (int i = 0; i < explosion.size(); i++) {
			explosion[i].update(ts);
		}
	}
}

void Firework::render(Renderer * renderer)
{
	if (!exploded) {
		//Do rocket render
		rocket.render(renderer);
	}
	else {
		//Do explosion render
		for (int i = 0; i < explosion.size(); i++) {
			if(!explosion[i].particle->expire())
				explosion[i].render(renderer);
		}
	}
}

void Firework::destroy()
{
	//Destroy Fireworks
}
