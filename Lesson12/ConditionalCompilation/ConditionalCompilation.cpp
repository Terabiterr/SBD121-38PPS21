#include <iostream>
using namespace std;

class Cat {
public:
    static void SayMau() { std::cout << "May" << std::endl; }
};

#define CAT Cat::SayMau()

#ifdef CAT
    bool yes = 1;
#endif


int main()
{
    if (yes == true)
        cout << "The cat said:" << endl;
    else
        cout << "The cat did not say:" << endl;
}
