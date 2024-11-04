
#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include "Player.h"
#include "DebugText.h"
#include <iostream>

class Game {
public:
	enum action { 
		UP = 0, 
		LEFT = 1, 
		RIGHT = 2, 
		FIRE = 3,
		ALIVE = 4
	};

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void updateShip(const int& action, bool down);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Event event;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player player;
	DebugText debugtext;
};

#endif /* Game_hpp */
