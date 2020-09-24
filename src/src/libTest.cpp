#include <iostream>
#include "asr.h"

using namespace std;

/*
	This file is just for testing purposes.
	When launching you should get a window with an image saying "HI".
	Deleting this file won't affect the functionality of the renderer.
	However make sure to include the asr.h header file in your cpp file.
*/

asr a;
vect2D v = { 0,0 };

void drawBlue();
void drawWhite();
void finland();
void p1();

int libTest(int argc, char* argv[]) {

	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not be initialized! SDL Error: " << SDL_GetError() << endl;
	}

	a.setResolution(1000, 500);
	a.setBlockSize(100);
	a.initialize();

	a.showRender(10000);


	a.quit();
	return EXIT_SUCCESS;
	

	return 0;
}

void drawBlue() {
	colorDim blue = colorDim(0, 0, 255, 0);
	int b = a.getBlockSize();
	a.draw(blue, v);
	v.x = v.x + b;
}

void drawWhite() {
	colorDim white = colorDim(255, 255, 255, 1);
	int b = a.getBlockSize();
	a.draw(white, v);
	v.x = v.x + b;
}

void finland() {

	p1();

	a.nextLine(&v);

	p1();

	for (int i = 0; i < 10; i++) {
		drawBlue();
	}

	a.nextLine(&v);

	for (int i = 0; i < 10; i++) {
		drawBlue();
	}

	a.nextLine(&v);

	p1();

	a.nextLine(&v);

	p1();

	a.nextLine(&v);
}

void p1() {
	drawWhite();
	drawWhite();

	drawBlue();

	for (int i = 0; i < 76; i++) {
		drawWhite();
	}
}