#include <iostream>
#include "Car.h"
#include "Audi.h"
#include "BMW.h"
#include "Car.cpp"
#include "Audi.cpp"
#include "BMW.cpp"

template<class T>
void PolimorphDisplay(Car<T> * car) // Динамический Полиморфизм функция
{
    cout << car->ToString() << endl;
}

int main()
{
    Audi<int> audi;
    BMW<int> bmw;

    Car<int>* car; // один интерфейс, много реализаций Динамический Полиморфизм
    //AUDI
    car = &audi;
    car->SetParams(3, "{\"model\" : 100,\"color\" : \"red\",\"capacity\" : 2.3}");
    car->SetParams(6, "{\"wheels\" : 4,\"doors\" : 5}");
    cout << "##### audi 100 #####" << endl;
    PolimorphDisplay(car);
    // BMW
    car = &bmw;
    car->SetParams(5, "{\"model\" : 520,\"color\" : \"black\",\"capacity\" : 2.0}");
    car->SetParams(11, "{\"wheels\" : 4,\"doors\" : 5}");
    car->SetParams(11, "{\"price\" : 25.700}");
    cout << "##### bmw 520 #####" << endl;
    PolimorphDisplay(car);
}