#include <iostream>

class InitWays
{
private:
    int x, y;
    double result;

public:
    InitWays(int x, int y) : x(x), y(y) {}
    int Plus()
    {
        return x + y;
    }
    int Minus()
    {
        return x - y;
    }
};

int main()
{
    InitWays waysCalc(6, 5);
    std::cout << "+:\t" << waysCalc.Plus() << std::endl;
    std::cout << "-:\t" << waysCalc.Minus() << std::endl;
}
