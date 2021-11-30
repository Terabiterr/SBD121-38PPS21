#pragma once
#include <string>
#include <iostream>
using namespace std;

class Interests
{
public:
	Interests();
	Interests(string thing);
	~Interests();
	string GetThing();
	void SetThing(string thing);
private:
	string thing;
};

