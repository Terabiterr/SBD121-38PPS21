#include "SmartPtr.h"

template<class T>
SmartPtr<T>::SmartPtr(T* ptr) : _ptr(ptr)
{
	cout << "Constructor:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
SmartPtr<T>::~SmartPtr()
{
	if (_ptr != nullptr) delete _ptr;
	cout << "Destructor:\t" << typeid(this).name() << "\t" << this << endl;
}

template<class T>
T& SmartPtr<T>::operator* ()
{
	return *_ptr;
}

template<class T>
T* SmartPtr<T>::operator-> ()
{
	return _ptr;
}
