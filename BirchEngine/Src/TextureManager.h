#pragma once
#include "Game.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren) {
		SDL_Surface* tempSurface = tempSurface = IMG_Load(filename);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
		SDL_FreeSurface(tempSurface);
		return tex;
	};
};