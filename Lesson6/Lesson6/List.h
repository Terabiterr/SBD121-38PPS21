#pragma once
#include <iostream>
using namespace std;

template<typename T1>
class Node; //Объявить Node т.к. он реализован после нашего класса. 

template<typename T>
class List
{
public:
	List();
	~List();
	void Add(T data);
	void Clear();
	int GetSize();
	Node<T>& GetHead();
	Node<T>& GetTail();
	void Insert(T data, int index);
	void Replace(T data, int index);
	void Delete(int index);
	T operator[] (int index);
	void DeleteFirst();
	void Sort(T& com);
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _size;
};

template<typename T1>
class Node { public: Node<T1>* next; Node<T1> * previous; T1 data; };