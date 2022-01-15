#include "Triangle.h"


template<class T>
Triangle<T>::Triangle() : Figure<T>(), h(0)
{
	cout << "Constructor default type:\t" << typeid(this).name() << "\t" << this << endl;
}
template<class T>
Triangle<T>::Triangle(T a, T h) : Figure<T>(a)
{
	this->h = h;
	cout << "Constructor with params type:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
Triangle<T>::~Triangle()
{
	cout << "Destructor type:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
T Triangle<T>::Area() // S = 0,5 * a * h
{
	return 0.5 * this->GetA() * h;
}

template<class T>
T Triangle<T>::GetH()
{
	return h;
}
