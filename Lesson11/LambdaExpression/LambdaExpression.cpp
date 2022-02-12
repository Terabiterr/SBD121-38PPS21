#include <iostream>

template<class T>
class ZXSpectrum48K {
public:
    T operator() (T instructionOne, T instructionTwo)
    {
        return instructionOne + instructionTwo;
    }
};

int main()
{
    ZXSpectrum48K<double> Z80;
    std::cout << Z80(50, 25); // Функтор
    return 0;
}
