#include "Square.h"

template<class T>
Square<T>::Square() : Figure<T>()
{
	cout << "Constructor default type:\t" << typeid(this).name() << "\t" << this << endl;
}
template<class T>
Square<T>::Square(T a, T b) : Figure<T>(a, b)
{
	cout << "Constructor with params type:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
Square<T>::~Square()
{
	cout << "Destructor type:\t" << typeid(this).name() << "\t" << this << endl;
}