#include <iostream>

#include "TextureManager.h"
#include "Shader.h"
#include "Window.h"
#include "glfwWindow.h"
#include "openGLHandler.h"
#include "BallGenerator.h"
#include "Clock.h"
#include "Camera.h"


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

	Shader shaderProgram("minimal.vert", "single.frag"); // Initialize Shader Programs

	BallGenerator ballGen(vec3(0.0f,0.0f,-10.0f), vec3(0.0f, 5.0f, 0.0f), &textureManager, &shaderProgram, &Camera2D);
	ballGen.init();

	Clock appClock;
	appClock.startClock();
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
		double dt = (currentTime - previousTime) * 0.00001f; //Convert DT to seconds

		//End of DeltaTime
		if (frameClock.alarm()) {
			ballGen.update(dt); //updates balls
			previousTime = currentTime;
			graphicsHandler.start();  // Sets up Rendering Loop
			ballGen.render(); // Renders Balls
			graphicsHandler.end(); //Swap Buffers
			frameClock.resetClock(); // Once frame is done reset to 0
		}
	}
	ballGen.destroy();
	graphicsHandler.destroy();

	return 0;
}