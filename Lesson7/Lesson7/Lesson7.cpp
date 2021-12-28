#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

int main()
{
	Tree<int> tree;
	//Add Iteratively
/*	tree.AddIteratively(8);
	tree.AddIteratively(12);
	tree.AddIteratively(10);
	tree.AddIteratively(9);
	tree.AddIteratively(11);
	tree.AddIteratively(14);
	tree.AddIteratively(13);
	tree.AddIteratively(15);
	tree.AddIteratively(15); */ // Checking equal elements
	// Add Recursively
	tree.AddRecursively(8);
	tree.AddRecursively(12);
	tree.AddRecursively(10);
	tree.AddRecursively(9);
	tree.AddRecursively(11);
	tree.AddRecursively(14);
	tree.AddRecursively(13);
	tree.AddRecursively(15);
	tree.AddRecursively(15); // Checking equal elements
	//Show
	cout << "DisplayMaxMin:\n";
	tree.DisplayMaxMin();
	cout << "\n";
	cout << "DisplayMinMax:\n";
	tree.DisplayMinMax();
	cout << "\n";
}