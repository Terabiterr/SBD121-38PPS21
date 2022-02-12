#include <iostream>
#include <climits>
using namespace std;

class IOExceptionDivideByZero : exception
{
public:
	virtual char const* what() const override
	{
		return "Divide by zero:";
	}
};

static double Divide(double x, double y)
{
	if (x == 0 || y == 0)
		throw IOExceptionDivideByZero(); // Вызон исключительной ситуации IOExceptionDivideByZero
	return x / y;
}

int main()
{
	try
	{
		cout << Divide(5, 0) << endl; // Деление на ноль (Запрещено)
	}
	catch (const IOExceptionDivideByZero& ex) // 1 Проверка IOExceptionDivideByZero
	{
		cerr << ex.what() << endl;
		return 1;
	}
	catch(const exception& ex) // 2 Сделать неизвестное исключение
	{
		cout << ex.what() << endl;
	}
	catch (...) // 3 Если ничего не сработало, выдать неизвестное исключение в любом случае
	{
		cout << "unknow exception\t" << endl;
	}
	return 0;
}
