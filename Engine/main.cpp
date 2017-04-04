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
#include "SingleParticle.h"
#include "StaticEntity.h"
#include "SingleSpawn.h"
#include "Shoot.h"
#include "InputHandler.h"
#include "SDLWindow.h"
#include "ParticleFactory.h"

using namespace std;
using namespace glm;

int main(int argc, char *argv[])
{

	vec2 windowSize(800,600);
	//Window *window = new glfwWindow(windowSize.x, windowSize.y);
	Window *window = new SDLWindow(windowSize.x, windowSize.y);

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

	Shader minshaderProgram("minimal.vert", "single.frag"); // Minimal Shader Program
	Shader HSVshaderProgram("HSVVert.shader", "HSVFrag.shader");  // HSV Shader Program

	Transform transform;
	Material material;
	material.texture = "lava";
	
	Sprite *sprite = new Sprite("particle", &textureManager);
	ParticleFactory *factory = new ParticleFactory();
	factory->setTextureManager(&textureManager);

	//Particle *particle = ParticleFactory::makeParticle(1, &textureManager);

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

	Particle *particle = nullptr;
	InputHandler inputHandler("");
	Command command(factory, &ParticleFactory::createSingle);
	inputHandler.setCommand(command);

	bool running = true;
	while(running) {

		frameClock.updateClock(); // Ticks our Frame Clock
		appClock.updateClock(); //Ticks App Clock
		// Calculates Delta Time
		currentTime = appClock.getMilliseconds();
		double dt = (currentTime - previousTime)*0.0001f; //Convert DT to seconds
		
		//End of DeltaTime
		if (frameClock.alarm()) {
			if (particle != nullptr) {
				// Update Function
				particle->update(dt);
			}
			
			// End of Update
			graphicsHandler.start();  // Sets up Rendering Loop
			// Render Function

			if (particle != nullptr) {
				//particle.render(&glRenderer);
				glRenderer.renderObject(sprite);
			}
			// End of Render
			graphicsHandler.end(); //Swap Buffers
			frameClock.resetClock(); // Once frame is done reset to 0
			previousTime = currentTime;

			inputHandler.update(running, particle);
		}
	}
	graphicsHandler.destroy();
	MeshGenerator::destroy();

	return 0;
}