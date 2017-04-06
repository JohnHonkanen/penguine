/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "Particle.h"
#include "Spawner.h"
#include "DynamicEntity.h"
#include "Shapes.h"
class BasicParticle :
	public Particle
{
private:
	
	Shapes *particleShape;
	Spawner *spawn;
	Movement *particleMovement;
public:
	BasicParticle();
	BasicParticle(Particle *p, Entity *emitter, Shapes *shape, Spawner *spawn);
	~BasicParticle();
	void init();
	void update(float ts);
	void render(Renderer *renderer);
	void destroy();

	Entity *particle;
};
