#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector& otherVector); // Конструктор копирования
	Vector(Vector&& other); // Это не ссылка на ссылку, а это rvalue ссылка!
	~Vector();
	Vector<T>& operator= (const Vector& rightVector);
	Vector<T>& operator=(Vector&& other); // Это не ссылка на ссылку, а это rvalue ссылка!
	void pop_back(); // Удаляет элемент в конце вектора.
	void push_back(T item); // Добавляет элемент в конец вектора.
	friend ostream& operator<<<T> (ostream& out, const Vector& date); // Здесь и будет подчеркивать это нормально.
	int size();
private:
	T* _data;
	int _size;
};