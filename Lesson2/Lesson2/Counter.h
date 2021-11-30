#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Counter
{
public:
	static int counter;
	Counter();
	void SetCounter(int count);
	string ToString();
};

