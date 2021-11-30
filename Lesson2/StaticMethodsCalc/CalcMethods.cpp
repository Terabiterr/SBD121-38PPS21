#include "CalcMethods.h"

CalcMethods::CalcMethods()
{
	countObject++;
}

double CalcMethods::Plus(int x, int y)
{
	return x + y;
}

double CalcMethods::Minus(int x, int y)
{
	return x - y;
}

bool CalcMethods::Equal(int x, int y)
{
	//if(this->x == x) // Ошибка нельзя использовать this в статическом методе
	//cout << ToString() << endl; // Error
	return x == y;
}

string CalcMethods::ToString()
{
	stringstream ss;
	ss << "count objects:\t" << CalcMethods::countObject << "\n";
	return ss.str();
}
int CalcMethods::countObject = 0;
