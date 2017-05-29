#include "Application2D.h"
#include "defines.h"


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