#include "Game.hpp"

Game *game = NULL;

int main(int argc, char *argv[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init(
		"BirchEngine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		false
	);
	while (game->running()) {
		frameStart = SDL_GetTicks();
		game->handlerEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	return 0;
}