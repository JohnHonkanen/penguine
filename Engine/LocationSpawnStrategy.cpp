#include "LocationSpawnStrategy.h"

LocationSpawnStrategy::LocationSpawnStrategy(vec3 in_location)
{
	location = in_location;
}

LocationSpawnStrategy::~LocationSpawnStrategy()
{
}

void LocationSpawnStrategy::configureParticle(Entity &entity)
{
	entity.transform.translate(location);
}
