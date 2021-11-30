#include <iostream>
#include "Car.h"
using namespace std;

int main()
{
    //Init cars
    Car audi("audi", "red", 220);
    Car subaru("subaru", "blue", 320);
    Car bmw("bmw", "green", 280);
    Car opel("opel", "grey", 220);
    Car daewoo("daewoo", "white", 180);
    //Show cars
    cout << audi.ToString() << endl;
    cout << bmw.ToString() << endl;
    cout << opel.ToString() << endl;
    cout << daewoo.ToString() << endl;
    //Equals cars
    if (audi.Equal(audi))
    {
        cout << "audi and audi1 are equals" << endl;
    }
    else
    {
        cout << "Different!" << endl;
    }
    //Equals cars
    subaru.Equal(opel)
        ? cout << "equal" << endl
        : cout << "Doesn't equal" << endl;
    return 0;
}
