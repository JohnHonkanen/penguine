#include "ConeSpawn.h"



ConeSpawn::ConeSpawn(Entity * emitter, vec3 at, float baseSize)
{
	ConeSpawn::emitter = emitter;
	ConeSpawn::baseSize = baseSize;
}

ConeSpawn::~ConeSpawn()
{
}

void ConeSpawn::init()
{
	vec3 emitterPos = ConeSpawn::emitter->transform.getPosition();
	float baseX = (rand() % ((int) baseSize * 2 * 100))*0.01 - baseSize;
	float baseY = (rand() % ((int)baseSize * 2 * 100))*0.01 - baseSize;
	vec3 entityPos = vec3(baseX, baseY, 0);
	entityPos += emitterPos;
	ConeSpawn::entity->transform.setPosition(entityPos);
}

void ConeSpawn::update(float ts)
{
}
