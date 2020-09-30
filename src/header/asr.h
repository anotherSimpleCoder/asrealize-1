#pragma once
#include "render.h"
/*
	This is the asr class, which cotain all the important functions to run asr.
*/
class asr {
public:

	/*
		This initializes SDL, which is the backbone of asr. If there are any errors, these will be stated in the console.
	*/
	void initialize() {
		init();
	}

	/*
		This is the draw function, which is mainly resposible for constructing the image onto the window.
		It requires 2 parametres:
			colorDim c: A color vector for specifying the color, which should be drawn. (For more information look up colorDim.h)
			vect2D v: The 2-dimensional vector, which states the position, where it should be drawn.
	*/
	void draw(colorDim c, vect2D v) {
		drawColor(c, v);
	}

	/*
		This function is responsible for displaying the rendered result onto the window.

		Parameter:
			-t: the time for how long the rendered image should be shown
	*/
	void showRender(int t) {
		show(t);
	}

	/*
		goes to the next line by adding the block size to the y variable of the vector.
		Parameters:
			-v: pointer to the vector which should be modified
	*/
	void nextLine(vect2D* v) {
		v->x = 0;
		int blockS = getBS();
		v->y = v->y + blockS;
	}

	/*
		quit() is responsible to terminate the renderer properly.
	*/
	void quit() {
		SDL_Quit();
	}

	/*
	*	Gets the current block size.
	*/
	int getBlockSize() {
		int b = getBS();
		return b;
	}

	/*
		With setBlockSize the size of a color block can be changed.
		NOTE: Blocks in asr are represented as squares,
		parameter:
			b: the block size in pixels
	*/
	void setBlockSize(int b) {
		setBS(b);
	}

	/*
		Sets the resolution of the presenting window and the screen, which will be rendered on.

		parameters:
			- width: the width of the screen/window
			- height: the height of the screen/window
	*/
	void setResolution(int width, int height) {
		surf* screen = getS();
		screen->maxX = width;
		screen->maxY = height;
	}
};