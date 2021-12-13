#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

template<typename T>
Stack<T> StackAdd(Stack<T> stack, T item)
{
    stack.Push(item);
    return stack;
}

void main()
{
    Stack<int> stack;
    stack.Push(1); // Add an item to stack
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    cout << stack << endl;
    
    stack.Pop(); // delete an item from stack
    stack.Pop();
    cout << stack << endl;

    Stack<int> stack2{ move(stack) }; // Constructor movement
    cout << "stack2:" << endl;
    cout << stack2 << endl;
    cout << "stack:" << endl;
    cout << stack << endl;

    Stack<int> stack3; //Operator assignment
    stack3 = move(stack2);
    cout << "stack3:" << endl;
    cout << stack3 << endl;
    cout << "stack2:" << endl;
    cout << stack2 << endl;

    cout << "StackAdd(stack, 8):\t" << endl;
    stack = StackAdd(stack, 8); // Если удалить конструктор копирования, то компилятор будет требовать параметр по ссылке
    cout << "stack:" << endl;
    cout << stack << endl;

    stack.Push(10);
    stack.Push(152);
    stack.Push(352);
    stack.Push(5);
    stack.Push(88);
    cout << "stack:" << endl;
    cout << stack << endl;

    stack.SetCapacity(6);
    stack.Push(88);
    cout << "stack:" << endl;
    cout << stack << endl;

    stack.Push(88);
    cout << "stack:" << endl;
    cout << stack << endl;

    stack = stack3;
    cout << "stack:" << endl;
    cout << stack << endl;
}
