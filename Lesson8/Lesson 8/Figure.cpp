#include "Figure.h"

template<class T>
Figure<T>::Figure() : a(0), b(0)
{
	cout << "Constructor default type:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
Figure<T>::Figure(T a) : a(a), b(0)
{
	cout << "Constructor with one params type:\t" << typeid(this).name() << "\t" << this << endl;
}

template<typename T>
Figure<T>::Figure(T a, T b)
{
	this->a = a;
	this->b = b;
	cout << "Constructor with params type:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
Figure<T>::~Figure()
{
	cout << "Destructor type:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
T Figure<T>::GetA()
{
	return a;
}

template<class T>
T Figure<T>::GetB()
{
	return a;
}

template<class T>
T Figure<T>::Area()
{
	return a * b;
}


