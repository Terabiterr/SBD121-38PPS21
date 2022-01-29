#include "Audi.h"

template<class T>
Audi<T>::Audi() : Car<T>()
{
	cout << "Audi constructor default:\t" << this << endl;
}

template<class T>
Audi<T>::~Audi()
{
	cout << "Audi destructor:\t" << endl;
}

template<class T>
void Audi<T>::SetParams(T key, string jsonValue)
{
	this->_params.insert(pair<T, string>(key, jsonValue));
}

template<class T>
string Audi<T>::ToString()
{
	this->ss << "car:\t" << typeid(this).name() << endl;
	for (auto it = this->_params.begin(); it != this->_params.end(); it++)
		this->ss << "key: " << it->first << "\t" << "data: " << it->second << "\t\n";
	return this->ss.str();
}
