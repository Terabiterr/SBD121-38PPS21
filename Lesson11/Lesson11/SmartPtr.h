#pragma once
#include <iostream>
using namespace std;

template<class T>
class SmartPtr
{
	T* _ptr;
public:
	SmartPtr(T * ptr = nullptr);
	~SmartPtr();
	T& operator* ();
	T* operator-> ();
};