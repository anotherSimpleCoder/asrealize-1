#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "asr.h"

void fileHandle(std::string s);
void initialize(std::string* s);
void bodyHandle();
void lex(std::string s);
void extract();
void execute();
void present(int t);