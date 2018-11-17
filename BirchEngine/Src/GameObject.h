#pragma once
#include "Game.h"
#include "TextureManager.h"
class GameObject {
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren,int x,int y) {
		renderer = ren;
		objTexture = TextureManager::LoadTexture(texturesheet, ren);
		xpos = x;
		ypos = y;
	};
	~GameObject() {
	
	};
	void Update() {
		xpos++;
		ypos++;
		srcRect.h = 300;
		srcRect.w = 201;
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w / 2;
		destRect.h = srcRect.h / 2;
	};
	void Render() {
		SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	};
private:
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

};