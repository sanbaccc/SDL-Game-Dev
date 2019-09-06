#ifndef Game_HPP
#define Game_HPP
#include "SDL.h"
#include <stdio.h>
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void init(
		const char *title,
		int xpos,
		int ypos,
		int width,
		int height,
		bool fullscreen
	);
	void handlerEvents();
	void update();
	void render();
	void clean();
	bool running();

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

};

#endif


