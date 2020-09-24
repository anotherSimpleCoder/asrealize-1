#pragma once

/*
	surf structure is used to describe the screen resolution.
		maxX: the width
		maxY: the height
*/

struct surf {
	int maxX = 400;
	int maxY = 400;
};

/*
	Structure used for describing a 2-dimensional vector.

	x: x coordinate
	y: y coordinate
*/
struct vect2D {
	int x = 0;
	int y = 0;
};
