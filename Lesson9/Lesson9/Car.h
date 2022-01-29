#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
template<class T>
class Car
{
public:
	Car();
	virtual ~Car();
	virtual void SetParams(T, string) = 0;
	virtual string ToString() = 0;
protected:
	multimap<T, string> _params;
	stringstream ss;
};