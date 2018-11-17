#pragma once
#include "Game.h"
#include "TextureManager.h"
class Player {
public:
	Player(const char* texturesheet,int x,int y) {
		
		objTexture = TextureManager::LoadTexture(texturesheet);
		xpos = x;
		ypos = y;
		
		indiceX = 0;
		indiceY = 0;
		cambio = 13;
	};
	~Player() {
	
	};
	void Update() {
		srcRect.x = indiceX * 50;
		srcRect.y = indiceY * 75;
		srcRect.h = 75;
		srcRect.w = 50; 
		
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w ;
		destRect.h = srcRect.h ;
		
	};
	void Move(int cont) {
		if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym) {
		case SDLK_UP:
			indiceY = 1;
			if(cont%cambio == 0){
				if (indiceX >= 0 && indiceX < 3 && (cont%cambio == 0)) {
					indiceX++;
				}
				else if (indiceX) {
					indiceX = 0;
				}
			}
			
			ypos--;
			break;
		case SDLK_DOWN:
			indiceY = 0;
			if (cont%cambio == 0) {
				if (indiceX >= 0 && indiceX < 3 && (cont%cambio == 0)) {
					indiceX++;
				}
				else if (indiceX) {
					indiceX = 0;
				}
			}
			ypos++;
			break;
		case SDLK_RIGHT:
			indiceY = 3;
			
			if (cont%cambio == 0) {
				if (indiceX >= 0 && indiceX < 3 && (cont%cambio == 0)) {
					indiceX++;
				}
				else if (indiceX) {
					indiceX = 0;
				}
			}
			xpos++;

			break;
		case SDLK_LEFT:
			indiceY = 2;
			if (cont%cambio == 0) {
				if (indiceX >= 0 && indiceX < 3 && (cont%cambio == 0)) {
					indiceX++;
				}
				else if (indiceX) {
					indiceX = 0;
				}
			}
			xpos--;
			break;

		}
		}
		if (Game::event.type == SDL_KEYUP) {

		}
	}
	void trans() {
		if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_UP:
				indiceY = 1;
				if (indiceX >= 0 && indiceX < 3) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				
				break;
			case SDLK_DOWN:
				indiceY = 0;
				if (indiceX >= 0 && indiceX < 3) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				
				break;
			case SDLK_RIGHT:
				indiceY = 3;

				if (indiceX >= 0 && indiceX < 3) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				

				break;
			case SDLK_LEFT:
				indiceY = 2;
				if (indiceX >= 0 && indiceX < 3) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				
				break;

			}
		}
	}
	void Render() {
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	};
private:
	int xpos;
	int ypos;
	int indiceX;
	int indiceY;
	int cambio;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	

};