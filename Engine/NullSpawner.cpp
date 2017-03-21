#include "NullSpawner.h"

NullSpawner * NullSpawner::instance = nullptr;

NullSpawner::NullSpawner()
{
}

NullSpawner::~NullSpawner()
{
}

NullSpawner * NullSpawner::getInstance()
{
	if (NullSpawner::instance == nullptr)
		NullSpawner::instance = new NullSpawner();

	return NullSpawner::instance;
}

mat4 NullSpawner::init()
{
	return mat4();
}

mat4 NullSpawner::update(float ts)
{
	return mat4();
}

bool NullSpawner::spawn()
{
	return true;
}

Entity * NullSpawner::createEntity()
{
	return nullptr;
}
