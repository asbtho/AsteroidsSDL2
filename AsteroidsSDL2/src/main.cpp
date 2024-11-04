#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {
	// Variables for fps in loop
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("AsteroidsDEV", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);

	while (game->running()) {
		frameStart = SDL_GetTicks(); // Get milliseconds since SDL lib init

		game->handleEvents(); // Handle inputs
		game->update();		  // Update objects, locations, etc.
		game->render();		  // Draw objects

		frameTime = SDL_GetTicks() - frameStart; // Calculate one frame's time

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime); // Wait before rendering next frame
		}
	}

	game->clean();

	return 0;
}
