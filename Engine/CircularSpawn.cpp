#include "CircularSpawn.h"
CircularSpawn::CircularSpawn(Entity * emitter, float radius, int numberOfPoints, float startAngle)
{
	CircularSpawn::emitter = emitter;
	CircularSpawn::radius = radius;
	CircularSpawn::numberOfPoints = numberOfPoints;
	CircularSpawn::angle = startAngle;
	CircularSpawn::step = (M_PI*0.5f) / numberOfPoints;
	angle = 0.0f + (M_PI*0.25f);
}

CircularSpawn::~CircularSpawn()
{
}

void CircularSpawn::init()
{
	if (angle > (M_PI*0.75))
		angle = 0.0f + (M_PI*0.25f);
	vec3 emitterPos = CircularSpawn::emitter->transform.getPosition();
	float x = cos(angle) * radius;
	float y = sin(angle) * radius;
	CircularSpawn::circularPoint = vec2(x, y);
	vec3 entityPos = vec3(x, y, -10.0f);
	CircularSpawn::entity->transform.setPosition(entityPos + emitterPos);
	angle += step;
}

void CircularSpawn::update(float ts)
{
}
