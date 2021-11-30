#include "Compiler.h"

Compiler::Compiler(const Compiler& other) // Constructor copy
{
	this->count = other.count;
	this->code = new Code[other.count];
	for (size_t i = 0; i < other.count; i++)
	{
		this->code[i] = other.code[i];
	}
}

Compiler::Compiler()
{
	count = 0;
	code = NULL; // nullptr
}

Compiler::Compiler(Code * code, const int size) // problem copy here
{
	count = size;
	this->code = code;
}

Compiler::~Compiler()
{
	cout << "Compiler Destroyed:\t" << this << endl;
	delete[] code;
}

void Compiler::Assemble()
{
	for (int i = 0; i < count; i++)
	{
		cout << code[i].GetName() << endl;
	}
}

Code * Compiler::GetCodeDone()
{
	return code;
}

int Compiler::GetCount()
{
	return count;
}

