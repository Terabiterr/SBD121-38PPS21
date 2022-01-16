#pragma once
#include "Figure.h"

template<class T>
class Triangle : public Figure<T>
{
public:
	Triangle();
	Triangle(T a, T h); // где a — основание, h — высота
	~Triangle();
	T Area(); // S = 0,5 * a * h
	T GetH();
private:
	T h;
};
