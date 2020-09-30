#pragma once
#include <stdlib.h>

/*
    This is the colorDim class, which represents color. It will be used for specifying color to the framework of asr (SDL).
    It is constructed the following way:
        r = red value
        g = green value
        b = blue value
        a = alpha value
*/

class colorDim {
private:
    uint8_t r; //red value
    uint8_t g; //green value
    uint8_t b; //blue value
    uint8_t a; //alpha value

public:
    colorDim() = default;

    //The constructor of the class, which is needed for declaring instances of colorDim.
    colorDim(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }

    //returns the red value of the colorDim instance
    uint8_t getR() {
        return r;
    }

    //returns the green value of the colorDim instance
    uint8_t getG() {
        return g;
    }

    //returns the blue value of the colorDim instance
    uint8_t getB() {
        return b;
    }

    //returns the alpha value of the colorDim instance
    uint8_t getA() {
        return a;
    }


};

