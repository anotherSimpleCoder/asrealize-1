#include <iostream>
#include <string>
#include "asrFile.h"

using namespace std;

void readFile(string p, int t);
void version();

int main(int argc, char *argv[]) {
	string flag;
	if (argc >= 2) {
		flag = argv[1];
	}

	if (flag == "-asr") {
		if (argc != 4) {
			cout << "Error! Missing arguments!" << endl;
			return 0;
		}

		else {
			string path = argv[2];
			const char* time = argv[3];
			int t = atoi(time);
			readFile(path, t);
		}
		
	}

	if (flag == "-ver") {
		if (argc > 2) {
			cout << "Error! Too many parameters!" << endl;
			return 0;
		}

		version();
	}

	return 0;
}

void readFile(string p, int t) {
	fileHandle(p);
	bodyHandle(t);
}

void version() {
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << "ASRealize1 Interpreter for ASRscript" << endl;
	cout << "------------------------------------" << endl;
	cout << endl;
	cout << "Developed by anotherSimpleCoder" << endl;
	cout << endl;
	cout << endl;
	cout << "About the Interpreter:" << endl;
	cout << "----------------------" << endl;
	cout << "Version: 1.1" << endl;
	cout << "Language: ASRscript (standard alpha)" << endl;
	cout << "Dependent libraries: SDL2, ASR" << endl;
	cout << endl;
	cout << endl;
	cout << "About the Developer" << endl;
	cout << "-------------------" << endl;
	cout << "Name: anotherSimpleCoder" << endl;
	cout << "Github: https://github.com/anotherSimpleCoder/" << endl;
	cout << "Contact: asimplecoder@protonmail.com" << endl;
	cout << "Projects: ASR v1, ASRscript (standard alpha), ASRealize1" << endl;
	cout << endl;

}