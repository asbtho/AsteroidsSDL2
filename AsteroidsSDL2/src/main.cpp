#define SDL_MAIN_HANDLED
#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {
	// Variables for fps in loop
	const double target_fps = 60;
	double target_frame_time = 1 / (double) target_fps; // Target frame time in seconds
	double frame_start;
	float fps_interval = 1.0;
	float fps_lasttime = SDL_GetTicks(); //the last recorded time.
	float fps_current; //the current FPS.
	float fps_frames = 0; //frames passed since the last recorded fps.
	double delta_time = target_frame_time;

	game = new Game();

	game->init("AsteroidsDEV", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);

	while (game->running()) {
		frame_start = SDL_GetTicks(); // Get milliseconds since SDL lib init

		game->handleEvents(); 		// Handle inputs
		game->update(delta_time);	// Update objects, locations, etc.
		game->render();		  		// Draw objects

		delta_time = (SDL_GetTicks() - frame_start) / 1000.0;
		if (delta_time < target_frame_time) { 
			SDL_Delay((target_frame_time - delta_time) * 1000.0); // Wait before rendering next frame
			delta_time = target_frame_time;
		}

		fps_frames++;
		if (fps_lasttime < SDL_GetTicks() - fps_interval * 1000){
			fps_lasttime = SDL_GetTicks();
			fps_current = fps_frames;
			fps_frames = 0;
		}
		game->setCurrentFPS(fps_current);
	}

	game->clean();

	return 0;
}
