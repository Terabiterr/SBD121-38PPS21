#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CalcMethods
{
public:
	CalcMethods();
	static int countObject;
	static double Plus(int x, int y);
	static double Minus(int x, int y);
	static bool Equal(int x, int y);
	string ToString();
};
