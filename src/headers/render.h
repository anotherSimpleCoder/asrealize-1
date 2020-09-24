#pragma once
#include "SDL.h"
#include "screen.h"
#include "colorDim.h"


/*
	This headxer file contains all the functions of the render.cpp
*/

/*
	The explaination to this function is availale in asr.h
*/
void init();

/*
	The explaination to this function is availale in asr.h
*/
void render();

/*
	The explaination to this function is availale in asr.h
*/
void drawColor(colorDim c,  vect2D v);

/*
	The explaination to this function is availale in asr.h

	Parameter:
		-time: the time for how long it should be shown
*/
void show(int time);

/*
	Gets the current block size.	
*/
int getBS();

/*
	Sets the block size.
	Parameters:
		- x: the new block size
*/
void setBS(int x);

/*
	Getss the screen structure.
*/
surf* getS();

