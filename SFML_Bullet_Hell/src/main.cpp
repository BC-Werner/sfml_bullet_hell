#include "stdafx.h"

#include "Game.h"

int main()
{
	Game game(800, 600, "SFML Bullet Hell");
	game.run();

	return EXIT_SUCCESS;
}