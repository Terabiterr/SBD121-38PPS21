#pragma once
#include <iostream>
#include <ostream>
#include <climits>

using namespace std;

template<typename T>
class Stack
{
public:
	Stack(); // Конструктор по умолчанию
	Stack(const Stack& other); // Конструктор копирования
	Stack(Stack&& other); // Конструктор перемещения
	~Stack(); // Деструктор
	Stack<T>& operator=(Stack&& other); // Оператор перемещения
	Stack<T>& operator=(const Stack& other); // Оператор присваивания
	friend ostream& operator<<<T> (ostream& out, const Stack& stack); // Перегрузка оператора в поток
	bool IsEmpty(); // Проверяет, является ли stack пустым.
	void Pop(); // Удаляет элемент из верхней части stack.
	void Push(T item); // Добавляет элемент в верхнюю часть stack.
	int GetSize(); //Возвращает количество элементов в контейнере stack.
	void SetCapacity(int capacity); // Увеличить или уменьшить емкость стека
private:
	T* _data;
	int _size;
	int _capacity;
};