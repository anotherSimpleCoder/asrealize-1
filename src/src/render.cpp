#include <iostream>
#include "render.h"

using namespace std;


SDL_Window* window;
SDL_Renderer* renderer;
int blockSize = 100;
surf screen;


void init() {
	window = SDL_CreateWindow("2D Render", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen.maxX, screen.maxY, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		cout << "Window could not be created! SDL Error: " << SDL_GetError();
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) {
		cout << "Window could not be created! SDL Error: " << SDL_GetError();
	}
}


void drawColor(colorDim c,vect2D v) {
	SDL_Rect fillRect;
	fillRect.x = v.x;
	fillRect.y = v.y;
	fillRect.w = blockSize;
	fillRect.h = blockSize;

	uint8_t r = c.getR();
	uint8_t g = c.getG();
	uint8_t b = c.getB();
	uint8_t a = c.getA();

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &fillRect);
}

void show(int time) {
	SDL_RenderPresent(renderer);
	SDL_Delay(time);

}

int getBS(){
	return blockSize;
}

void setBS(int b) {
	blockSize = b;
}

surf* getS() {
	return &screen;
}