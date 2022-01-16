#pragma once
#include "Figure.h"

template<class T>
class Rectangle : public Figure<T>
{
public:
	Rectangle();
	Rectangle(T a, T b);
	~Rectangle();
};