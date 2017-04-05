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

	Clock appClock;
	appClock.startClock();
	appClock.setDelay(1000);
	Clock frameClock;
	frameClock.startClock();
	frameClock.setDelay(1000.0f/60); // 60FPS
	
	double previousTime = 0.0f;
	double currentTime = 0.0f;

	InputHandler inputHandler("");
	Command command(factory, &ParticleFactory::createFireWork);
	inputHandler.setCommand(command);

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
	MeshGenerator::destroy();

	return 0;
}