#pragma once
#include <iostream>
#include <stack>
#include <string>

using namespace std;

template<class T>
class Tree
{
public:
	Tree();
	~Tree();
	void AddIteratively(T data);
	void AddRecursively(T data);
	void DisplayMaxMin();
	void DisplayMinMax();
	T& GetRoot();
private:
	class Node 
	{ 
	public: 
		~Node() // Так как Node это отдельный объект, то у каждого нода свой деструктор
		{
			if (right != nullptr)
			{
				cout << "Destructor right:\t" << right->data << this << endl;
				delete right;
			}
			if (left != nullptr)
			{
				cout << "Destructor left:\t" << left->data << this << endl;
				delete left;
			}
		}
		T data;
		Node* right; 
		Node* left; 
	};
	Node* _root;
	void AddRecursivelyNode(Node** root, Node** newNode); // Рекурсивный обход дерева
	void DisplayRecursivelyMaxMin(Node** root); // Display max - min
	void DisplayRecursivelyMinMax(Node** root); // Display max - min
};