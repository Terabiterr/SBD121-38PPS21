#pragma once
#include "Figure.h"
template<class T>
class Square : public Figure<T>
{
public:
	Square();
	Square(T a, T b);
	~Square();
};
