#include "List.h"

template<typename T>
List<T>::List() : _head(nullptr), _tail(nullptr), _size(0)
{
	cout << "Constructor default:\t" << this << endl;
}

template<typename T>
List<T>::~List()
{
	cout << "Destructor:\t" << this << endl;
	Clear();
}

template<typename T>
void List<T>::Add(T data)
{
	_size++; // количество элементов в листе
	Node<T>* tmp = new Node<T>; // Новый элемент всегда равен последнему элементу в списке (new дал новый адрес)
	tmp->data = data; // Добавить в новый адрес элемент
	tmp->next = nullptr; // Так как это последний элемент, то он указывает на nullptr
	tmp->previous = _tail; // Так как это previous, то указываем сразу на предыдущий (С этой строкой получаем двухсвязный список)

	if (_head == nullptr) // Если list пустой и это первый заход
	{
		_head = _tail = tmp; // И голова и хвост равны первому элементу (Берем адрес первого элемента)
		return; // Первый элемент добавлен успешно можно делать return
	}

	_tail->next = tmp; // Хвост указывает на последний элемент
	_tail = tmp; // Хвост это последний элемент в списке (Присвоить новый адрес в объект _tail)
}

template<typename T>
void List<T>::Clear()
{
	while (_head != nullptr)
	{
		Node<T>* tmp = _head;
		_head = _head->next;
		delete tmp;
		_size--;
	}
	_size = 0;
	_head = _tail = nullptr;
	cerr << "The list is empty:\t" << "elements in the list\t" << _size << endl;
}

template<typename T>
int List<T>::GetSize()
{
	return _size;
}

template<typename T>
Node<T>& List<T>::GetHead()
{
	return *(_head); // получить ссылку на объект Node
}

template<typename T>
Node<T>& List<T>::GetTail()
{
	return *(_tail);
}

template<typename T>
void List<T>::Insert(T data, int index)
{
	if (_size <= index || index < 0)
		throw std::bad_alloc(); // exception памяти

	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	Node<T>* previous = _head;
	Node<T>* next = _head;

	while (index-- != 0)
	{
		previous = next; // Предыдущий перед вставкой
		next = next->next; // Следующий после вставки
	}
	previous->next = newNode; // Следующий элемент у предыдущего -> это new node
	newNode->next = next; // И новый элемент его следующий -> это next
	++_size;
}

template<typename T>
void List<T>::Replace(T data, int index)
{
	if (_size <= index || index < 0)
		throw std::bad_alloc(); // exception памяти

	Node<T>* target = _head;

	while (index-- != 0)
	{
		target = target->next; // Цель
	}
	target->data = data; // Заменить данные
}

template<typename T>
void List<T>::Delete(int index)
{
	if (_size <= index || index < 0)
		throw std::bad_alloc(); // exception памяти

	Node<T>* previous = nullptr;
	Node<T>* target = _head;
	Node<T>* next = nullptr;

	if (index > 0)
	{
		while (index-- != 0)
		{
			previous = target;
			target = target->next; // Получили цель
		}
		next = target->next; // Получить от цели следующий элемент
		delete target; // Удалить цель
		previous->next = next; // Указать предыдущему элементу на следующий
		--_size;
	}
	else
	{
		DeleteFirst();
	}
}

template<typename T>
T List<T>::operator[](int index)
{
	if (_size <= index || index < 0)
		throw std::bad_alloc(); // exception памяти
	Node<T>* tmp = _head;
	while (index-- != 0)
		tmp = tmp->next;
	return tmp->data;
}

template<typename T>
void List<T>::DeleteFirst()
{
	Node<T>* previous = _head;
	_head = _head->next;
	delete previous;
	_size--;
}