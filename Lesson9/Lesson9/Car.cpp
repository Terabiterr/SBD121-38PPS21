#include "Car.h"
template<class T>
Car<T>::Car()
{
	cout << "Constructor base Car:\t" << this << endl;
}

template<class T>
Car<T>::~Car()
{
	cout << "Car destructor:\t" << endl;
}
