#include "Game.h"
#include "Player.h"

Game::Game() {
}

Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		debugtext.init(renderer);

		isRunning = true;
	} else {
		isRunning = false;
	}
}

void Game::updateShip(const int& action, bool down){
	if (down) {
		switch (action) {
		case Game::LEFT:
			player.rotate(Player::LEFT);
			break;
		case Game::RIGHT:
			player.rotate(Player::RIGHT);
			break;
		}
	} else {
		switch (action) {
		case Game::LEFT:
			player.rotate(Player::NONE);
			break;
		case Game::RIGHT:
			player.rotate(Player::NONE);
			break;
		}
	}
}

void Game::handleEvents() {
	while(SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT) {
			isRunning = false;
			break;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_LEFT ||
				event.key.keysym.scancode == SDL_SCANCODE_A) {
				updateShip(Game::LEFT, true);
			}
			else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT ||
				event.key.keysym.scancode == SDL_SCANCODE_D) {
				updateShip(Game::RIGHT, true);
			}
		}
		if (event.type == SDL_KEYUP) {
			if (event.key.keysym.scancode == SDL_SCANCODE_LEFT ||
				event.key.keysym.scancode == SDL_SCANCODE_RIGHT ||
				event.key.keysym.scancode == SDL_SCANCODE_A ||
				event.key.keysym.scancode == SDL_SCANCODE_D) {
				updateShip(Game::LEFT, false);
			}
		}
	}
}

void Game::update() {
	player.updatePosition(); // Runs player update position function
	player.trace();			 // Runs player trace lines function based on angle and x, y location
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set background color black
	SDL_RenderClear(renderer);						// Clear screen with background color
	player.draw(renderer);							// Run player draw function
	debugtext.draw(renderer);						// Draw debug text
	SDL_RenderPresent(renderer);					// Present new screen with drawed objects
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
