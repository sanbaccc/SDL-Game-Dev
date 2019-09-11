#include "TextureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const char *fileName, SDL_Renderer *renderer) {
	SDL_Surface *surface = IMG_Load(fileName);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return tex;
}