#include <iostream>
using namespace std;

class Admin {
public:
    Admin() { cout << typeid(this).name() << endl; }
};


typedef time_t double; // неправильно
typedef double time_t; // правильно


typedef Admin User;

int main()
{
    User user;

}
