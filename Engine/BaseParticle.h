/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "Particle.h"
#include "Entity.h"
#include "Spawner.h"
class BaseParticle :
	public Particle
{
public:
	BaseParticle(Entity*);
	virtual ~BaseParticle();
	void init();
	void render();
	void update(float ts);
	void destroy();
	Entity *entity;
	Spawner *spawn;
};

