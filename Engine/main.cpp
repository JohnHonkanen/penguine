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
#include "SpriteRenderer.h"

using namespace std;
using namespace glm;

int main(int argc, char *argv[])
{

	vec2 windowSize(800,600);
	Window *window = new glfwWindow(windowSize.x, windowSize.y);
	openGLHandler graphicsHandler(window);
	Camera Camera2D;
	Camera2D.setPerspectiveProjection(radians(45.0f), float(windowSize.x)/float(windowSize.y), 0.1f, 100.0f); // Set Projection
	Camera2D.setView(vec3(0.0f, 0.0f, -10.0f)); // Adjusts our Camera Back

	graphicsHandler.init(); // Initialize Rendering Library

	TextureManager textureManager;
	textureManager.saveTexture("smoke.png", "smoke");
	textureManager.saveTexture("fire.png", "fire");
	textureManager.saveTexture("lava.jpg", "lava");

	Shader shaderProgram("minimal.vert", "single.frag"); // Initialize Shader Program

	Transform transform;
	Material material;
	material.texture = "lava";

	Sprite *sprite = new Sprite("fire", &textureManager);
	Sprite *sprite = new Sprite("lava", &textureManager);
	
	SpriteRenderer spriteRenderer(&transform, &shaderProgram, &Camera2D);
	spriteRenderer.setShape(sprite);

	BoxRenderer boxRenderer(material, &textureManager, &transform, &shaderProgram, &Camera2D);

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
		double dt = (currentTime - previousTime)*0.001f; //Convert DT to seconds
		
		//End of DeltaTime
		if (frameClock.alarm()) {
			// Update Function
			
			//transform.translate(vec3(0,1*dt,0));
			transform.rotate(45.0f*dt, vec3(0, 0, 1), false);
			mat4 model = transform.calculateModelMatrix();


			// End of Update
			graphicsHandler.start();  // Sets up Rendering Loop
			// Render Function
			spriteRenderer.renderObject();
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