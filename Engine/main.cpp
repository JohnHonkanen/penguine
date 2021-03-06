/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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
#include "InputHandler.h"
#include "SDLWindow.h"
#include "ParticleFactory.h"
#include "ParticleManager.h"
#include "FireworkDisplay.h"
#include "ParticleFactoryCommand.h"
#include "ParticleManagerCommand.h"


using namespace std;
using namespace glm;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	vec2 windowSize(800,600);
	//Window *window = new glfwWindow(windowSize.x, windowSize.y);
	Window *window = new SDLWindow(windowSize.x, windowSize.y);

	openGLHandler graphicsHandler(window);
	Camera Camera2D;
	Camera2D.setPerspectiveProjection(radians(45.0f), float(windowSize.x)/float(windowSize.y), 0.1f, 100.0f); // Set Projection
	//Camera2D.setOrthoProjection(vec3(-500.0f, -500.0f, 0.1f), vec3(500.0f, 500.0f, 100.0f));
	Camera2D.setView(vec3(0.0f, 0.0f, -10.0f)); // Adjusts our Camera Back

	graphicsHandler.init(); // Initialize Rendering Library

	TextureManager::setContext(OPENGL);
	TextureManager *textureManager = TextureManager::getManager();
	textureManager->saveTexture("smoke.png", "smoke");
	textureManager->saveTexture("fire.png", "fire");
	textureManager->saveTexture("lava.jpg", "lava");
	textureManager->saveTexture("particle.png", "particle");

	Shader minshaderProgram("minimal.vert", "single.frag"); // Minimal Shader Program
	Shader HSVshaderProgram("HSVVert.shader", "HSVFrag.shader");  // HSV Shader Program

	Transform transform;
	Material material;
	material.texture = "lava";
	
	ParticleFactory *factory = new ParticleFactory();
	factory->setTextureManager(textureManager);


	GLRenderer glRenderer(&HSVshaderProgram);
	glRenderer.setCamera(&Camera2D);

	//StaticEntity emitter = StaticEntity();
	//emitter.transform.translate(0, -0, -0);
	//FireworkDisplay firework(&emitter);
	//firework.init();
	//ParticleManager::getManager()->addParticle(&firework);


	Clock appClock;
	appClock.startClock();
	appClock.setDelay(1000);
	Clock frameClock;
	frameClock.startClock();
	frameClock.setDelay(1000.0f/60); // 60FPS
	
	double previousTime = 0.0f;
	double currentTime = 0.0f;

	InputHandler inputHandler("");
	ParticleFactoryCommand *createFirework = new ParticleFactoryCommand(factory, &ParticleFactory::createFireWork);
	ParticleFactoryCommand *createParticle = new ParticleFactoryCommand(factory, &ParticleFactory::createBasicParticle);
	ParticleManagerCommand *stopUpdate = new ParticleManagerCommand(&ParticleManager::toggleRun);
	inputHandler.setCommand(0, createFirework);
	inputHandler.setCommand(1, stopUpdate);
	inputHandler.setCommand(2, createParticle);

	cout << endl;
	cout << "Welcome to project Penguine! "<< endl;
	cout << "--------------------------------------- " << endl;
	cout << "Please select one or more of the following commands to generate particles onto your display" << endl;
	cout << "S: Pause the render display from updating" << endl;
	cout << "A: Spawn a single particle with collision detection" << endl;
	cout << "Space: Spawn a particle emitter and shoot fireworks!!" << endl;
	cout << "Escape: Exit the application" << endl;
	cout << "--------------------------------------- " << endl;
	cout << endl << endl;

	bool running = true;
	while(running) {

		frameClock.updateClock(); // Ticks our Frame Clock
		appClock.updateClock(); //Ticks App Clock
		// Calculates Delta Time
		
		currentTime = appClock.getMilliseconds();
		float dt = (currentTime - previousTime) *0.001f; //Convert DT to seconds
				
		//End of DeltaTime
		if (frameClock.alarm()) {

			inputHandler.update(running);

			// End of Update
			graphicsHandler.start();  // Sets up Rendering Loop
			// Render Function

			// Update Function
			ParticleManager::getManager()->update(dt);
			// End of Update
			graphicsHandler.start();  // Sets up Rendering Loop
			// Render Function
			ParticleManager::getManager()->render(&glRenderer);

			// End of Render
			graphicsHandler.end(); //Swap Buffers
			frameClock.resetClock(); // Once frame is done reset to 0
			previousTime = currentTime;
		}
	}
	graphicsHandler.destroy();
	//MeshGenerator::destroy();

	return 0;
}