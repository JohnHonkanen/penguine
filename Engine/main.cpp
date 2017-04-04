#include <iostream>

#include "TextureManager.h"
#include "Shader.h"
#include "Window.h"
#include "glfwWindow.h"
#include "openGLHandler.h"
#include "Clock.h"
#include "MeshGenerator.h"
#include "Camera.h"
#include "BoxRenderer.h"
#include "Sprite.h"
#include "GLRenderer.h"
#include "BasicParticle.h"
#include "StaticEntity.h"
#include "Spawner.h"
#include "Shoot.h"
#include "LocationSpawnStrategy.h"
#include "EntitySpawnStrategy.h"
#include "DelayedSpawn.h"
#include "LifeTimeSpawn.h"
#include "ParticleManager.h"

using namespace std;
using namespace glm;

int main(int argc, char *argv[])
{

	vec2 windowSize(800,600);
	Window *window = new glfwWindow(windowSize.x, windowSize.y);
	openGLHandler graphicsHandler(window);
	Camera Camera2D;
	Camera2D.setPerspectiveProjection(radians(45.0f), float(windowSize.x)/float(windowSize.y), 0.1f, 100.0f); // Set Projection
	//Camera2D.setOrthoProjection(vec3(-500.0f, -500.0f, 0.1f), vec3(500.0f, 500.0f, 100.0f));
	Camera2D.setView(vec3(0.0f, 0.0f, -10.0f)); // Adjusts our Camera Back

	graphicsHandler.init(); // Initialize Rendering Library

	TextureManager textureManager;
	textureManager.saveTexture("smoke.png", "smoke");
	textureManager.saveTexture("fire.png", "fire");
	textureManager.saveTexture("lava.jpg", "lava");
	textureManager.saveTexture("particle.png", "particle");

	Shader shaderProgram("minimal.vert", "single.frag"); // Initialize Shader Program

	Transform transform;
	Material material;
	material.texture = "lava";

	Sprite sprite = Sprite("particle", &textureManager);
	StaticEntity emitter = StaticEntity();
	emitter.transform.translate(0, -0, -0);

	AbstractSpawnStrategy *locStrat = new LocationSpawnStrategy(vec3(0, -0, -50));
	EntitySpawnStrategy spawnStrat(locStrat, &emitter);
	DelayedSpawn delay(&spawnStrat, 2000);
	LifeTimeSpawn life(&delay, 100);

	Spawner spawn;
	spawn.setSpawnStrategy(&life);
	spawn.setSpawnEntity(new DynamicEntity(&sprite));
	spawn.setEmitterEntity(&emitter);
	spawn.setMovementStrategy(new Shoot(vec3(0, 100, 0)));
	
	ParticleManager *pManager = ParticleManager::getManager();
	
	BasicParticle particle(nullptr, &emitter, &sprite, &spawn);
	particle.init();

	pManager->addParticle(&particle);

	GLRenderer glRenderer(&shaderProgram);
	glRenderer.setCamera(&Camera2D);


	Clock appClock;
	appClock.startClock();
	appClock.setDelay(1000);
	Clock frameClock;
	frameClock.startClock();
	frameClock.setDelay(1000.0f/60); // 60FPS
	
	double previousTime = 0.0f;
	double currentTime = 0.0f;
	bool flag = true;
	while(flag) {

		frameClock.updateClock(); // Ticks our Frame Clock
		appClock.updateClock(); //Ticks App Clock
		// Calculates Delta Time
		
		currentTime = appClock.getMilliseconds();
		float dt = (currentTime - previousTime) *0.001f; //Convert DT to seconds
				
		//End of DeltaTime
		if (frameClock.alarm()) {
			// Update Function
			pManager->update(dt);
			// End of Update
			graphicsHandler.start();  // Sets up Rendering Loop
			// Render Function
			pManager->render(&glRenderer);
			// End of Render
			graphicsHandler.end(); //Swap Buffers
			frameClock.resetClock(); // Once frame is done reset to 0
			previousTime = currentTime;
		}
	}
	graphicsHandler.destroy();
	MeshGenerator::destroy();

	return 0;
}