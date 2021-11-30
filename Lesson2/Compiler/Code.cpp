#include "Code.h"

Code::Code()
{
	name = "";
	code = "";
}

Code::Code(string name, string code)
{
	this->name = name;
	this->code = code;
}

Code::~Code()
{
	cout << "Destroyed Code:\t" << this << endl;
}

string Code::GetName()
{
	return name;
}

string Code::GetCode()
{
	return code;
}

void Code::SetName(string name)
{
	this->name = name;
}

void Code::SetCode(string code)
{
	this->code = code;
}
