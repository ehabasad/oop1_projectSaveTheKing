#include "Controller.h"
#include <iostream>

int main()
{
	Controller play;

	srand(time(NULL));

	play.run();

	return EXIT_SUCCESS;
}