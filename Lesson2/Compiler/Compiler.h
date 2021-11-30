#pragma once
#include <iostream>
#include <string>
#include "Code.h"
using namespace std;

class Compiler
{
public:
	Compiler(const Compiler &other);
	Compiler();
	Compiler(Code * code, const int size);
	~Compiler();
	void Assemble();
	Code * GetCodeDone();
	int GetCount();
private:
	int count;
	Code * code;
};