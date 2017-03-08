#include "SDLRenderer.h"
#include "GLFWRenderer.h"
#include "BallGenerator.h"
#include "Shoot.h"
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	GLFWRenderer renderer;
	renderer.init();
	BallGenerator bg(vec3(0,0,0), vec3(0,500,0));
	bg.init();
	while (true) {

		//bg.update(0.01f);
		renderer.start();
		renderer.drawVerts();
		//renderer.loadTextures();
		//bg.render(&renderer);
		//Do something in main
		renderer.end();
	}
	renderer.destroy();
	return 0;
}
