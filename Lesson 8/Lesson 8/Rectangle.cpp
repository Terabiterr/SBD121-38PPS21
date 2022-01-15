#include "Rectangle.h"

template<class T>
Rectangle<T>::Rectangle() : Figure<T>()
{
	cout << "Constructor default type:\t" << typeid(this).name() << "\t" << this << endl;
}
template<class T>
Rectangle<T>::Rectangle(T a, T b) : Figure<T>(a, b)
{
	cout << "Constructor with params type:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
Rectangle<T>::~Rectangle()
{
	cout << "Destructor type:\t" << typeid(this).name() << "\t" << this << endl;
}
