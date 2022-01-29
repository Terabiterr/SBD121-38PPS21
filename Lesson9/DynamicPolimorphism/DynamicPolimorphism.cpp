#include <iostream>
#include <string>
using namespace std;

class Phone {
public:
    virtual void Call() = 0;
};

class Nokia : public Phone {
public:
    void Call() override { cout << typeid(this).name() << endl; }
};
class Samsung : public Phone {
public:
    void Call() override { cout << typeid(this).name() << endl; }
};

void PhoneCall(Phone& phone) { phone.Call(); }

void main()
{
    PhoneCall(*new Nokia);
    PhoneCall(*new Samsung);
}
