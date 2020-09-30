#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "asr.h"

/*
	This header file declares the interface for the ASRealize1 interpreter.
*/

/*
	Handles the .asr ASRscript file. 
	Parameters:
		- p: Path of the .asr file
*/
void fileHandle(std::string p);

/*
	Initializes the renderer and framework by extracting the neccesary data out of the meta section and also checks, if the meta section got declared correctly.
	Parameters:
		- s: Array, which contains the two properties of the meta section as a string.
*/
void initialize(std::string* s);

/*
	Handles the body section of the .asr file by skipping the already read meta section and checking if the body expression got declared correctly.
	Parameters:
		- t: The amount of time in ms for showing the render.
*/
void bodyHandle(int t, std::string s);

/*
	Makes a lexical analysis of the code by detecting the symbols and adding its respective token to the token List. (More info about tokens in token.h)
	Parameter:
		- s: one line of code
*/
void lex(std::string s);

/*
	Extracts the information and values out of the token and value list and saves these values into the respective variables.
*/
void extract();

/*
	Executes the rendering with the already initialized renderer.
*/
void execute();

/*
	Presents the finished render onto the already initialized window.
	Parameter:
		- t: amount of time for how long the render should be presented (in ms).
*/
void present(int t);