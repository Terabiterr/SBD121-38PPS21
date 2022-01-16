#include <iostream>
using namespace std;

class A { // Private
public:
    A() { cout << "Constructor:\t" << typeid(this).name() << endl; }
    ~A() { cout << "Destructor:\t" << typeid(this).name() << endl; }
    void Display() { cout << "Dicplay:\t" << typeid(this).name() << endl; };
};
class B : public A { // Private
public:
    B() { cout << "Constructor:\t" << typeid(this).name() << endl; }
    ~B() { cout << "Destructor:\t" << typeid(this).name() << endl; }
    void Display() { cout << "Dicplay:\t" << typeid(this).name() << endl; };
};
class C : public B, public A { // Множественное наследование (Multiple inheritance)
public:
    C() { cout << "Constructor:\t" << typeid(this).name() << endl; }
    ~C() { cout << "Destructor:\t" << typeid(this).name() << endl; }
};

//int main()
//{
//    C c;
//    ((B)c).Display();
//}