﻿// пример https://docs.microsoft.com/ru-ru/cpp/cpp/user-defined-type-conversions-cpp?view=msvc-160
#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    explicit Money(double _amount) : amount{ _amount } {}; // Если убрать explicit, то не будет ошибок в main на 22 строке
    double amount;
};

void display_balance(const Money balance) // неявное преобразование 
{
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main(int argc, char* argv[])
{
    Money payable{ 79.99 };        // Legal: direct initialization is explicit.

    display_balance(payable);      // Legal: no conversion required
   // display_balance(49.95);        // Error: no suitable conversion exists to convert from double to Money.
    display_balance((Money)9.99f); // Legal: explicit cast to Money

    return 0;
}
