#pragma once
#include <iostream>

using namespace std;

template<class T>
class Figure
{
public:
	Figure();
	Figure(T a);
	Figure(T a, T b);
	~Figure();
	T GetA();
	T GetB();
	T Area();
private:
	T a, b;
};