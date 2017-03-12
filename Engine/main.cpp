#include <iostream>

#include "TextureManager.h"
#include "Shader.h"
#include "Window.h"
#include "glfwWindow.h"
#include "openGLRenderer.h"
#include "BallGenerator.h"
#include "Clock.h"


using namespace std;
using namespace glm;

int main(int argc, char *argv[])
{

	Window *window = new glfwWindow(800, 600);
	openGLRenderer renderer(window);
	renderer.init(); // Initialize Rendering Library

	TextureManager textureManager;
	textureManager.saveTexture("awesomeface.png", "container");

	Shader shaderProgram("minimal.vert", "single.frag"); // Initialize Shader Programs

	BallGenerator ballGen(vec3(0.0f,0.0f,0.0f), vec3(0.0f, 150.0f, 0.0f), &textureManager, &shaderProgram);
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
			renderer.start();  // Sets up Rendering Loop
			ballGen.render(&renderer); // Renders Balls
			renderer.end(); //Swap Buffers
			frameClock.resetClock(); // Once frame is done reset to 0
		}
	}
	ballGen.destroy();
	renderer.destroy();

	return 0;
}