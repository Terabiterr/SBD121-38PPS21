#include "Date.h"

Date::Date()
{
	_day = 1;
	_month = 1;
	_year = 2000;
	cout << "Constructor default:" << endl;
}

Date::Date(int day, int month, int year)
{
	_day = (day >= 1 && day <= 31) ? day : 1;
	_month = (month >= 1 && month <= 12) ? month : 1;
	_year = year > 2000 ? year : 2000;
	cout << "Constructor with params:" << endl;
}

const Date& Date::operator+= (const Date& right)
{
	_day += right._day;
	_month += right._month;
	_year += right._year;
	ShiftDate31();
	return *this;
}

const Date& Date::operator-= (const Date& right)
{
	_day -= right._day;
	_month -= right._month;
	_year -= right._year;
	ShiftDate31();
	return *this;
}

bool Date::operator!= (const Date& right)
{
	return _day != right._day && _month != right._month && _year != right._year;
}

bool Date::operator== (const Date& right)
{
	return _day == right._day && _month == right._month && _year == right._year;
}

bool Date::operator<= (const Date& right)
{
	if (_year <= right._year)
		return true;
	else if (_year > right._year)
		return false;
	else if (_month <= right._month)
		return true;
	else if (_month > right._month)
		return false;
	else if (_day <= right._day)
		return true;
	else if (_day > right._day)
		return false;
	else
		return false;
}

bool Date::operator>= (const Date& right)
{
	if (_year >= right._year)
		return true;
	else if (_year < right._year)
		return false;
	else if (_month >= right._month)
		return true;
	else if (_month < right._month)
		return false;
	else if (_day >= right._day)
		return true;
	else if (_day < right._day)
		return false;
	else
		return false;
}

bool Date::operator< (const Date& right)
{
	if (_year < right._year)
		return true;
	else if (_year > right._year)
		return false;
	else if (_month < right._month)
		return true;
	else if (_month > right._month)
		return false;
	else if (_day < right._day)
		return true;
	else if (_day > right._day)
		return false;
	else
		return false;
}

bool Date::operator> (const Date& right)
{
	if (_year > right._year)
		return true;
	else if (_year < right._year)
		return false;
	else if (_month > right._month)
		return true;
	else if (_month < right._month)
		return false;
	else if (_day > right._day)
		return true;
	else if (_day < right._day)
		return false;
	else
		return false;
}

Date& Date::operator= (const Date& right) // Date d1; Date d2; d1 = d2;
{
	if (this == &right)
		return *this;
	_day = right._day,
	_month = right._month,
	_year = right._year;
	return *this;
}

const Date Date::operator+ (const Date& right)
{
	_day = _day + right._day,
	_month = _month + right._month,
	_year = _year + right._year;
	ShiftDate31();
	return Date(*this);
}

const Date Date::operator- (const Date& right)
{
	_day = _day - right._day,
		_month = _month - right._month,
		_year = _year - right._year;
	ShiftDate31();
	return Date(*this);
}

Date& Date::operator++()
{
	++_day;
	++_month;
	++_year;
	ShiftDate31();
	return *this;
}

Date& Date::operator--()
{
	--_day;
	--_month;
	--_year;
	ShiftDate31();
	return *this;
}

Date Date::operator++(int)
{
	Date tmpDate(_day, _month, _year);
	++(*this);
	ShiftDate31();
	return tmpDate;
}

Date Date::operator--(int)
{
	Date tmpDate(_day, _month, _year);
	--(*this);
	ShiftDate31();
	return tmpDate;
}

Date& Date::operator[](const int index) // Вернуть элемент по индексу
{
	return this[index];
}

void* Date::operator new[](size_t size) // здесь не size, а размер в байтах
{
	cout << "new[]:\t" << size << endl;
	void* pointToDate = malloc(size); // функция выделения памяти от языка C
	if (!pointToDate) // Проверить если 0
	{
		throw std::bad_alloc(); // Исключение
	}
	return pointToDate;
}

void Date::operator delete[](void* datePtr) // Указатель на наш массив
{
	cout << "delete[]:\t" << datePtr << endl;
	free(datePtr); // функция очистка памяти от языка C
}

void Date::ShiftDate31() // Сдвиг даты если в месяце 31 день
{
	if (_day < 1) // If days less then 31
		while (_day < 1) { _day += 31; _month--; }

	if (_month < 1) // If months more then 31
		while (_month < 1) { _month += 12; _year--; }

	if (_day > 31) // If days more then 31
		while (_day > 31) { _day -= 31; _month++; }

	if (_month > 12) // If months more then 31
		while (_month > 12) { _month -= 12; _year++; }

	if (_day <= 0) _day = 1;
	if (_month <= 0) _month = 1;
	if (_year < 2000) _year = 2000;
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << "dd:mm:yyyy ";
	if (date._day < 10)
	{
		out << "0" + to_string(date._day) << ":";
	}
	if (date._day >= 10)
	{
		out << to_string(date._day) << ":";
	}
	if (date._month < 10)
	{
		out << "0" + to_string(date._month) << ":";
	}
	if (date._month >= 10)
	{
		out << to_string(date._month) << ":";
	}
	out << to_string(date._year);
	return out;
}
