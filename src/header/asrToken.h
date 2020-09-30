#pragma once

/*
	Enumeration of the token, which are used to build the structre of the code in a list so that it can be handled easier by the interpreter.
	Also it is used to check if the code in the asr File is syntactically correct.
*/
enum class token {
	OB, CB, COM, COL, VAL, NUL
};