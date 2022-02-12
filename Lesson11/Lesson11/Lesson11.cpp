#include <iostream>
#include "SmartPtr.h"
#include "SmartPtr.cpp"
#include <string>
using namespace std;

class User 
{
public:
    User(int id, string name) : _id{ id }, _name{ name }
    {
        cout << "Constructor:\t" << typeid(this).name() << "\t" << this << endl;
    }
    void SetId(int id) { _id = id; }
    int GetId() { return _id; }
    void SetName(string name) { _name = name; }
    string GetName() { return _name; }
private:
    int _id;
    string _name;
};

int main()
{
    /*
        С помощью умных указателей нам теперь не нужно думать об очистке памяти, она будет очищена автоматически.
        Умный указатель сам очищает память. 
    */
    const int size = 5;
    SmartPtr<User> user1(new User(1, "Bob")); // Выделение памяти, но нет delete,

    cout << user1->GetId() << endl; // Работает за счет перегрузки оператора ->
    cout << user1->GetName() << endl;

    (*user1).SetName("Alex"); // Работает за счет перегрузки оператора *
    cout << (*user1).GetName() << endl;
}
