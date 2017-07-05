#include "Application2D.h"
#include "defines.h"
//Proived bootstrap main file. Modified all other files in Project 2d

int main()
{
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", SCREEN_WIDTH, SCREEN_HEIGHT, false);
	
	// deallocation
	delete app;

	return 0;
}