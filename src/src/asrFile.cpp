#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "asrFile.h"
#include "List.h"
#include "intList.h"


using namespace std;

int width, height = 0;
int bs = 0;

int x, y = 0;
uint8_t r = 0;
uint8_t g = 0;
uint8_t b = 0;
uint8_t a = 0;
List iTokens;
intList vals;
asr ASR;


int charToInt(char c);
token charToToken(char c);
void registerNum(int g, int h);
void presentValues();

//Interpreting modules

void fileHandle(string s) {
	string c;
	string k[2];
	fstream f;

	int counter = 0;

	f.open(s, ios::in);

	getline(f, c);

	if (c == "meta{") {
		while (counter != 2) {
			if (c != "}") {
				getline(f, c);
				k[counter] = c;
				counter++;
			}
		}

		initialize(k);
	}

	else {
		cout << "Invalid file!" << endl;
		f.close();
		return;
	}

	f.close();
}

void initialize(string* s) {
	string resString = s[0];
	string blockString = s[1];

	stringstream rS(resString);
	string sec;
	int w, h;
	
	rS >> sec >> w >> h;


	stringstream bS(blockString);
	int b;

	bS >> sec >> b;

	width = w;
	height = h;
	bs = b;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not be initialized! SDL Error: " << SDL_GetError() << endl;
		return;
	}

	ASR.setResolution(width, height);
	ASR.setBlockSize(bs);
	ASR.initialize();
}

void bodyHandle() {
	fstream f;
	string c;

	f.open("test.asr", ios::in);

	getline(f, c);

	while (c != "body:") {
		getline(f, c);
	}

	while (!f.eof()) {
		getline(f, c);
		lex(c);
		extract();
		execute();
	}
	present(10000);
}

void lex(string s) {
	token convTok;
	token temp;
	bool wasDigit = false;
	int num = 0;
	int vC = 0;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		convTok = charToToken(c);

		if (convTok == token::VAL) {
			num = num * 10 + charToInt(c);
			wasDigit = true;
		}

		else {
			if (wasDigit) {
				temp = convTok;
				convTok = token::VAL;
				iTokens.addNode(convTok);
				vals.addNode(num);
				iTokens.addNode(temp);
				num = 0;
				wasDigit = false;
			}

			else {
				iTokens.addNode(convTok);
			}
		}
		
	}
}

void extract() {
	token cT = token::NUL;
	bool isOpened = false;
	bool wasVal = false;
	int valCount = 0;

	while (iTokens.isEmpty() == false) {
		cT = iTokens.getHeadData();

		if (cT == token::OB) {
			if (isOpened == false) {
				isOpened = true;
				iTokens.deleteHead();
			}

			else {
				cout << "Error! Last bracket didn't got closed!" << endl;
				return;
			}
		}

		if (cT == token::CB) {
			if (isOpened == true) {
				wasVal = false;
				isOpened = false;
				iTokens.deleteHead();
			}

			else {
				cout << "Error! There was never a bracket to be closed" << endl;
				return;
			}
		}

		if (cT == token::COM) {
			if (wasVal == true) {
				iTokens.deleteHead();
			}

			else {
				cout << "Error! A comma got added although there was no number before it!" << endl;
				return;
			}
		}

		if (cT == token::COL) {
			if (isOpened == false) {
				iTokens.deleteHead();
			}

			else {
				cout << "Error! A colon got added although there was no closing bracket before it!" << endl;
				return;
			}
		}

		if (cT == token::VAL) {
			int num = vals.getHeadData();
			registerNum(valCount, num);
			valCount++;
			wasVal = true;
			iTokens.deleteHead();
			vals.deleteHead();
		}

		if (cT == token::NUL) {
			iTokens.deleteHead();
		}
	}
}

void execute() {
	colorDim c = colorDim(r, g, b, a);
	vect2D v = { x,y };

	ASR.draw(c, v);
}

void present(int t) {
	ASR.showRender(t);
}


//Helping functions

void registerNum(int i, int j) {
	switch (i) {
	case 0:
		x = j;
		break;

	case 1:
		y = j;
		break;

	case 2:
		r = j;
		break;

	case 3:
		g = j;
		break;

	case 4:
		b = j;
		break;

	case 5:
		a = j;
		break;
	}
}

int getWidth() {
	return width;
}

int getHeight() {
	return height;
}

int getBlockSize() {
	return bs;
}

int charToInt(char c) {
	int g = (int)(c);
	g = g - 48;
	return g;
}

void presentValues() {


	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "r: " << (int)(r) << endl;
	cout << "g: " << (int)(g) << endl;
	cout << "b: " << (int)(b) << endl;
	cout << "a: " << (int)(a) << endl;
}

token charToToken(char c) {
	token x = token::NUL;


	switch (c) {

	case '(':
		//OB
		x = token::OB;
		break;


	case ')':
		//CB
		x = token::CB;
		break;


	case ',':
		//COM
		x = token::COM;
		break;


	case ':':
		//COL
		x = token::COL;
		break;

	case ' ':
		break;

	default:
		if (isdigit(c)) {
			int b = charToInt(c);
			x = token::VAL;
			break;
		}
	}

	return x;
}