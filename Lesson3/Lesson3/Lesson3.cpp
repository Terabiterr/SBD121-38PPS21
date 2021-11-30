#include <iostream>
#include "Date.h"

//Нужно придумать пример explicit

int main()
{
	Date date2{ 30, 12, 2500 };
	Date date3{ 30, 12, 2500 };

	date2++;
	date2++;
	date2++;
	cout << date2 << endl;

	const int size = 5;
	Date dates[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << dates[i] << endl;
	}

	Date* datesPoints = new Date[2]; // 12 байт
	delete[] datesPoints;
}

