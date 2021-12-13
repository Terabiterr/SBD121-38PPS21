#include "Stack.h"
template<typename T>
Stack<T>::Stack() : _data(nullptr), _size(0), _capacity(5)
{
	cout << "Constructor default:\t" << this << endl;
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	_capacity = other._capacity;
	_size = other._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	cout << "Copy constructor:\t" << this << endl;
}

template<typename T>
Stack<T>::Stack(Stack&& other) : _data(nullptr), _size(0)
{
	_capacity = other._capacity;
	_data = other._data;
	_size = other._size;
	other._data = nullptr; // Присвоить указателю nullpter что бы деструктор лишний раз не срабатывал
	other._size = 0;
	cout << "Constructor movement:\t" << this << endl;
}

template<typename T>
Stack<T>::~Stack()
{
	if (_data != nullptr)
	{
		cout << "Destructor:\t" << this << endl;
		delete[] _data;
	}
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& other)
{
	cout << "Operator assignment:\t" << this << endl;
	delete[] _data;
	_capacity = other._capacity;
	_data = other._data;
	_size = other._size;
	other._data = nullptr; // Присвоить указателю nullpter что бы деструктор лишний раз не срабатывал
	other._size = 0;
	other._capacity = 0;
	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this == &other)
		return *this;
	_capacity = other._capacity;
	_size = other._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	cout << "Copy operator=:\t" << this << endl;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	if (_data == nullptr)
		return true;
	return false;
}

template<typename T>
void Stack<T>::Pop()
{
	if (!IsEmpty())
	{
		T* temp = new T[--_size];
		for (size_t i = 1; i < _size + 1; i++)
			temp[i - 1] = _data[i];
		delete[] _data;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_data[i] = temp[i];
		delete[] temp;
	}
	if (_size == 0)
		_data = nullptr;
}

template<typename T>
void Stack<T>::Push(T item)
{
	if (_capacity <= _size)
	{
		cout << "******** stackoverflow ******** --->>>\t" << item << endl;
		return;
	}
	if (!IsEmpty())
	{
		T* temp = new T[_size];
		for (size_t i = 0; i < _size; i++)
			temp[i] = _data[i];
			delete[] _data;
		_data = new T[++_size];
		for (size_t i = 1; i < _size; i++)
			_data[i] = temp[i - 1];
		delete[] temp;
		_data[0] = item;
	}
	else
	{
		_data = new T[++_size];
		_data[0] = item;
	}
}

template<typename T>
int Stack<T>::GetSize()
{
	return _size;
}

template<typename T>
void Stack<T>::SetCapacity(int capacity)
{
	if (capacity <= _size || capacity >= INT_MAX)
	{
		cout << "******** stackoverflow ******** --->>>\t" << capacity << endl;
		return;
	}
	_capacity = capacity;
}

template<typename T>
ostream& operator<< (ostream& out, const Stack<T>& stack) // Здесь стандартная реализация
{
	out << "Capacity:\t" << stack._capacity << endl;
	for (size_t i = 0; i < stack._size; i++)
	{
		out << stack._data[i] << "\t";
	}
	return out;
}
