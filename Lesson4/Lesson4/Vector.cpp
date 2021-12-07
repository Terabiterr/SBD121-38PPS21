#include "Vector.h"
template<typename T>
Vector<T>::Vector() : _data(nullptr), _size(0)
{
	cout << "Constructor default:\t" << this << endl;
}

template<typename T>
Vector<T>::Vector(const Vector& otherVector)
{
	cout << "Copy Constructor:\t" << this << endl;
	_size = otherVector._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = otherVector._data[i];
	}
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) : _data(nullptr), _size(0)
{
	_data = other._data;
	_size = other._size;
	// Присвоить указателю nullpter что бы деструктор лишний раз не срабатывал
	other._data = nullptr;
	other._size = 0;
	cout << "Constructor movement:\t" << this << endl;
}

template<typename T>
Vector<T>::~Vector()
{
	if (_data != nullptr)
	{
		cout << "Destructor:\t" << this << endl;
		delete[] _data;
	}
}

template<typename T>
Vector<T>& Vector<T>::operator= (const Vector& rightVector)
{
	cout << "Operator = (const Vector& rightVector):\t" << this << endl;
	if(this == &rightVector)
		return *this;
	_size = rightVector._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = rightVector ._data[i];
	}
	return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector<T>&& other) // rvalue
{
	cout << "Operator assignment:\t" << this << endl;
	delete[] _data;
	_data = other._data;
	_size = other._size;

	// Присвоить указателю nullpter что бы деструктор лишний раз не срабатывал
	other._data = nullptr;
	other._size = 0;
	return *this;
}

template<typename T>
void Vector<T>::pop_back()
{
	if (_data != nullptr)
	{
		T* temp = new T[--_size]{ 0 };
		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = _data[i];
		}
		delete[] _data;
		_data = new T[_size]{ 0 };
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = temp[i];
		}
		delete[] temp;
	}
}

template<typename T>
void Vector<T>::push_back(T item) // Добавляет элемент в конец вектора. 
{
	if (_data != nullptr)
	{
		T* temp = new T[++_size];
		for (size_t i = 0; i < _size - 1; i++)
		{
			temp[i] = _data[i];
		}
		delete[] _data;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = temp[i];
		}
		delete[] temp;
		_data[_size - 1] = item;
	}
	else
	{
		_size = 1;
		_data = new T[_size];
		_data[_size - 1] = item;
	}
}
template<typename T>
int Vector<T>::size()
{
	return _size;
}
template<typename T>
ostream& operator<<(ostream& out, const Vector<T>& vector) // Здесь стандартная реализация
{
	for (size_t i = 0; i < vector._size; i++)
	{
		out << vector._data[i] << "\t";
	}
	return out;
}
