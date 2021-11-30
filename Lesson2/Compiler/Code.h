#pragma once
#include <string>
#include <iostream>
using namespace std;
class Code
{
private:
	string name;
	string code;
public:
	Code();
	Code(string name, string code);
	~Code();
	string GetName();
	string GetCode();
	void SetName(string name = "HelloWorld.cpp");
	void SetCode(string code = "cout << 'Hello, World!' << endl;");
};

